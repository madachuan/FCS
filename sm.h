#include "ll.h"
#include "item.h"

extern unsigned short counter;

struct ll *cll_born(void);
struct ll *ll_init(struct ll *head, unsigned n, struct ll *(*born)());
