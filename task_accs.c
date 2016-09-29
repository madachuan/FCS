#include <string.h>

#include <vxWorks.h>
#include <taskLib.h>

#include "ll.h"
#include "task_accs.h"

void task_accs(void)
{
	static char buf[256];
	for (;;) {
		static unsigned sum;
		unsigned n = read(com1, buf + sum, 256 - sum);
		if (sum == 0 && buf[0] != 0xA5)
			continue;
		sum += n;
		if (sum > 256)
			goto CLEAN;
		if (sum < buf[1] + 2)
			continue;
		if (buf[buf[1] - 2] != 0xEE)
			goto CLEAN;
		if (buf[buf[1] - 1] != chkxor(&buf[1], buf[1] - 3))
			goto CLEAN;
		current = wr_sm(current, "accs_rx", buf, 256);
CLEAN:
		sum = 0;
		memset(buf, 0x00, 256);
	}
}
