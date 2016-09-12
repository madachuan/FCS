#include <string.h>

#include "task_gps.h"

void task_gps(void)
{
	static char pre[256];
	static char buf[256];
	for (;;) {
		static unsigned sum;
		unsigned n = read(com4, pre + sum, 256 - sum);
		if (sum == 0 && strstr(pre, "$GPHPD,") != pre)
			continue;
		sum += n;
		if (sum > 256)
			goto CLEAN;
		char *end = strstr(pre, "\r\n");
		if (!end)
			continue;
		if (*(end - 3) != '*')
			goto CLEAN;
		if (*(end - 2) >= '0' && *(end - 2) <= '9')
			if (*(end - 2) - 48 != chkxor(pre + 1,
						end - 4 - pre) >> 4) {
				goto CLEAN;
		else if (*(end - 2) >= 'A' && *(end - 2) <= 'F')
			if (*(end - 2) - 55 != chkxor(pre + 1,
						end - 4 - pre) >> 4)
				goto CLEAN;
		else
			goto CLEAN;
		if (*(end - 1) >= '0' && *(end - 1) <= '9')
			if (*(end - 1) - 48 != (chkxor(pre + 1,
						end - 4 - pre) & 0x0F))
				goto CLEAN;
		else if (*(end - 1) >= 'A' && *(end - 1) <= 'F')
			if (*(end - 1) - 55 != (chkxor(pre + 1,
						end - 4 - pre) & 0x0F))
				goto CLEAN;
		else
			goto CLEAN;
		memcpy(buf, pre, 256);
		current = wr_sm(current, "gps_rx", buf, 256);
CLEAN:
		sum = 0;
		memset(pre, 0x00, 256);
	}
}
