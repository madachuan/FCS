#include <ioLib.h>
#include <intLib.h>
#include <iv.h>

int com1;
int com4;

void relay(unsigned i, bool on)
{
	if (on)
		openJDQ(i);
	else
		closeJDQ(i);
}

void rly(unsigned n)
{
	if (n < 1)
		return;
	relay(n, 0);
	rly(n - 1);
}

void can(void)
{
	HK_CAN_INITIALIZE(1, 9, 0x00, 0x80, 0x0A, 0x00, 0xFF, 0x7F,
			0x00, 0xFF, 0xAA, 0x88, 0x81, 0x00, 0x88);
	intConnect((VOIDFUNCPTR *)INUM_TO_IVEC(10 + 0x20),
		(VOIDFUNCPTR)isr_can, 0);
	sysIntEnablePIC(10);
}

void com(void)
{
	tyCoXRPCIDrv();
	tyCoXRPCIDevCreate("/tjat/0", 0, 256, 256, 32, 32);
	tyCoXRPCIDevCreate("/tjat/3", 3, 256, 256, 32, 32);
	com1 = open("/tjat/0", O_RDWR, 0);
	com4 = open("/tjat/3", O_RDWR, 0);
	ioctl(com1, FIOBAUDRATE, 115200);
	ioctl(com4, FIOBAUDRATE, 115200);
}

void tmr(void)
{
	Tinterrupt(7);
	intConnect((VOIDFUNCPTR *)INUM_TO_IVEC(11 + 0x20),
		(VOIDFUNCPTR)isr_tmr, 0);
	sysIntEnablePIC(11);
	open_Tint();
}

void drv(void)
{
	rly(10);
	can();
	com();
	tmr();
}
