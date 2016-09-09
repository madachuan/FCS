#include "ll.h"
#include "item.h"

extern MSG_Q_ID mq_can;
extern int tid_can;
extern struct ll *current;
extern unsigned short counter;

struct ll *wr_sm(struct ll *p, char *ch, char (*data)[], unsigned len)
