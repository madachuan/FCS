#include "ll.h"
#include "item.h"

struct ll *cll_born(void);
struct ll *ll_init(struct ll *head, unsigned len, struct ll *(*born)());
