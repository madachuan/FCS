#include "isr.h"

unsigned char tick;
unsigned short counter;
bool int_gps;

void isr_tmr(void)
{
	tick++;
	if (counter < 29996) {
		counter += 4;
		int_gps = 0;
	} else
		int_gps = 1;
	semFlush(bs_tmr);
}

void isr_can(void)
{
	static char buf[13];
	if (!(INTERRUPT() & 0x01))
		return;
	if (!HK_RD_IR(1)) {
		RESET();
		can();
		return;
	}
	HK_CAN_RECEIVE(1, buf);
	msgQSend(mq_can, buf, 13, NO_WAIT, MSG_PRI_NORMAL);
}
