#include <vxWorks.h>
#include <taskLib.h>

#include "ll.h"

extern int tid_gps;
extern struct ll *current;
extern unsigned short counter;
extern int com4;

struct ll *wr_sm(struct ll *p, char *ch, char *data, unsigned n);
char chk_xor(char *p, unsigned n);
