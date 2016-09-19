#include <stdlib.h>
#include <string.h>

#include "task_gps.h"

char *rd_comma(char *data, unsigned n)
{
	if (!n)
		return (data);
	char *tmp = strchr(data, ',');
	if (tmp)
		return (rd_comma(tmp + 1, n - 1));
	return (rd_comma(tmp + 1, n));
}

double rd_gps(char *data, unsigned n)
{
	char buf[256];
	strcpy(buf, rd_comma(data, n));
	*rd_comma(buf, 1) = 0;
	return (atof(buf));
}

void task_gps(void)
{
	static char buf[256];
	for (;;) {
		static unsigned sum;
		unsigned n = read(com4, buf + sum, 256 - sum);
		if (sum == 0 && strstr(buf, "$GPHPD,") != buf)
			continue;
		sum += n;
		if (sum > 256)
			goto CLEAN;
		char *end = strstr(buf, "\r\n");
		if (!end)
			continue;
		if (*(end - 3) != '*')
			goto CLEAN;
		if (*(end - 2) >= '0' && *(end - 2) <= '9')
			if (*(end - 2) - 48 != chkxor(buf + 1,
						end - 4 - buf) >> 4) {
				goto CLEAN;
		else if (*(end - 2) >= 'A' && *(end - 2) <= 'F')
			if (*(end - 2) - 55 != chkxor(buf + 1,
						end - 4 - buf) >> 4)
				goto CLEAN;
		else
			goto CLEAN;
		if (*(end - 1) >= '0' && *(end - 1) <= '9')
			if (*(end - 1) - 48 != (chkxor(buf + 1,
						end - 4 - buf) & 0x0F))
				goto CLEAN;
		else if (*(end - 1) >= 'A' && *(end - 1) <= 'F')
			if (*(end - 1) - 55 != (chkxor(buf + 1,
						end - 4 - buf) & 0x0F))
				goto CLEAN;
		else
			goto CLEAN;
		counter = (rd_gps(2) - (int)rd_gps(2)) * 1000;
		current = wr_sm(current, "gps_rx", buf, 256);
CLEAN:
		sum = 0;
		memset(buf, 0x00, 256);
	}
}
