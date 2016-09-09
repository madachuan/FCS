#include <stdlib.h>
#include <string.h>

#include "sm.h"

static const unsigned max = 10000;

struct ll *sm(void)
{
	struct ll *head = ll_init(head, max, cll_born);
	return (head);
}

struct ll *wr_sm(struct ll *p, char *ch, char (*data)[], unsigned len)
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
	((struct item *)(p->key))->data = malloc(len);
	memcpy(((struct item *)(p->key))->data, data, len);
	((struct item *)(p->key))->ts = counter;
	return (p->next);
}

struct ll *rd_sm(struct ll *p, unsigned len, char *ch)
{
	if (!len)
		return (NULL);
	if (counter - ((struct item *)(p->prev-key))->ts > 3000)
		return (NULL);
	if (((struct item *)(p->prev->key))->ch == ch)
		return (p->prev);
	return (p->prev, len - 1, ch);
}
