#include <vxWorks.h>
#include <taskLib.h>

#include "ll.h"
#include "item.h"

extern int tid_gps;
extern struct ll *current;
extern unsigned short counter;
extern int com4;

struct ll *wr_sm(struct ll *p, char *ch, char (*data)[], unsigned n);
unsigned char chk_xor(unsigned char *p, unsigned n);
