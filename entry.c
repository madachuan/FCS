#include "ll.h"
#include "entry.h"

struct ll *current;

void entry(void)
{
	drv();
	current = sm();
	os();
}
