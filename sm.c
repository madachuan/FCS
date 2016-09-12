#include <stdlib.h>
#include <string.h>

#include "sm.h"

static const unsigned max = 10000;

struct ll *sm(void)
{
	struct ll *head = ll_init(head, max, cll_born);
	return (head);
}

struct ll *wr_sm(struct ll *p, char *ch, char (*data)[], unsigned n)
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
	((struct item *)(p->key))->data = malloc(n);
	memcpy(((struct item *)(p->key))->data, data, n);
	((struct item *)(p->key))->ts = counter;
	return (p->next);
}

struct ll *rd_sm(struct ll *p, unsigned n, char *ch)
{
	if (!n)
		return (NULL);
	if (counter - ((struct item *)(p->prev-key))->ts > 3000)
		return (NULL);
	if (((struct item *)(p->prev->key))->ch == ch)
		return (p->prev);
	return (p->prev, n - 1, ch);
}
