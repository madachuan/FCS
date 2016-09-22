#include <vxWorks.h>
#include <msgQLib.h>
#include <taskLib.h>

#include "ll.h"

extern MSG_Q_ID mq_can;
extern struct ll *current;
extern unsigned counter;

struct ll *wr_sm(struct ll *p, char *ch, char *data, unsigned n);
