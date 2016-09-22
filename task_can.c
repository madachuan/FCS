#include "task_can.h"

static const id[13] = {0x380A9010, 0x400A9020, 0x480A9030,
	0x500A9040, 0x580A9050, 0x600A9060, 0x680A9070, 0x700A9080,
	0x780A9090, 0x800A90A0, 0x880AC0B0, 0x900A80B0, 0x980A80B0};

char *ch_can_rx[13] = {"ir_rx", "sv_rx", "m1_rx", "m2_rx", "m3_rx", "m4_rx",
	"m5_rx", "m6_rx", "m7_rx", "m8_rx", "d1_rx", "d2_rx", "d3_rx"};

void task_can(void)
{
	static char buf[13];
	for (;;) {
		msgQReceive(mq_can, buf, 13, WAIT_FOREVER);
		if (buf[0] != 0x88)
			continue;
		for (unsigned i = 0; i < 13; i++)
			if (*(unsigned *)(buf + 1) == id[i])
				break;
		if (i > 12)
			continue;
		current = wr_sm(current, ch_can_rx[i], buf + 5, 8);
	}
}
