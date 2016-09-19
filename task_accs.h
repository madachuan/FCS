#include <vxWorks.h>
#include <taskLib.h>

#include "ll.h"

extern int tid_accs;
extern struct ll *current;
extern int com1;

struct ll *wr_sm(struct ll *p, char *ch, char *data, unsigned n);
char chk_xor(char *p, unsigned n);
