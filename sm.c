#include <stdlib.h>
#include <string.h>

#include "sm.h"

static const unsigned max = 10000;

struct ll *sm(void)
{
	struct ll *head = ll_init(head, max, cll_born);
	return (head);
}

void wr_sm(struct ll *p, char *ch, char rt, char (*data)[], unsigned len)
{
	if (!p)
		return;
	if (p->key) {
		if (((struct item *)(p->key))->data)
			free(((struct item *)(p->key))->data);
		free(p->key);
	}
	p->key = malloc(sizeof(struct item));
	((struct item *)(p->key))->ch = ch;
	((struct item *)(p->key))->rt = rt;
	((struct item *)(p->key))->data = malloc(len);
	memcpy(((struct item *)(p->key))->data, data, len);
	((struct item *)(p->key))->ts = counter;
}
