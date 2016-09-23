#include "task_sync.h"

char *ch_tx[8] = {"ir_tx", "sv_tx", "mls_tx",
	"d1_tx", "d2_tx", "d3_tx", "pss_tx", "accs_tx"};

char ir_tx[13];
char sv_tx[13];
char mls_tx[13];
char d1_tx[13];
char d2_tx[13];
char d3_tx[13];
char pss_tx[13];
char accs_tx[24];

static const id[7] = {0x000A6000, 0x080A2000, 0x10FA0F00,
	0x180A1000, 0x200A1000, 0x280A1000, 0xA80A0800};

static char *tx[8] = {ir_tx, sv_tx, mls_tx,
	d1_tx, d2_tx, d3_tx, pss_tx, accs_tx};

void id_can_tx(unsigned n)
{
	if (n < 1)
		return;
	*tx[n - 1] = 0x88;
	*(int *)(tx[n - 1] + 1) = id[n - 1];
	id_can_tx(n - 1);
}

void task_sync(void)
{
	id_can_tx(7);
	for (;;) {
		semTake(bs_tmr, WAIT_FOREVER);
		unsigned t = tick % 4;
		if (t < 3) {
			HK_CAN_WRITE(1, tx[t]);
			current = wr_sm(current, ch_tx[t], tx[t], 13);
		} else {
			static unsigned i;
			if (i > 3)
				i = 0;
			HK_CAN_WRITE(1, tx[3 + i]);
			current = wr_sm(current, ch_tx[3 + i], tx[3 + i], 13);
			i++;
		}
		if (!(tick % 250)) {
			write(com1, accs_tx, 24);
			current = wr_sm(current, ch_tx[7], tx[7], 24);
		}
	}
}
