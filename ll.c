#include <stdio.h>
#include <stdlib.h>

#include "ll.h"

struct ll *ll_born(void)
{
	struct ll *head = malloc(sizeof(struct ll));
	if (!head) {
		printf("The memory is not enough!");
		exit(-1);
	}
	head->key = NULL;
	head->next = NULL;
#ifdef DUAL_LINKED_LIST
	head->prev = NULL;
#endif
	return (head);
}

struct ll *cll_born(void)
{
	struct ll *head = malloc(sizeof(struct ll));
	if (!head) {
		printf("The memory is not enough!");
		exit(-1);
	}
	head->key = NULL;
	head->next = head;
#ifdef DUAL_LINKED_LIST
	head->prev = head;
#endif
	return (head);
}

struct ll *ll_ins(struct ll *head, struct ll *(*born)())
{
	if (head) {
		struct ll *tmp = head->next;
		head->next = malloc(sizeof(struct ll));
		if (!head->next) {
			printf("The memory is not enough!");
			exit(-1);
		}
		head->next->key = NULL;
		head->next->next = tmp;
#ifdef DUAL_LINKED_LIST
		head->next->prev = head;
		tmp->prev = head->next;
#endif
		return (head);
	}
	return (born());
}

struct ll *ll_init(struct ll *head, unsigned n, struct ll *(*born)())
{
	if (n)
		return (ll_init(ll_ins(head, born), n - 1, born));
	return (head);
}

struct ll *ll_del(struct ll *head)
{
	if (head) {
		if (head->next && head->next != head) {
			struct ll *tmp = head->next;
			head->next = tmp->next;
#ifdef DUAL_LINKED_LIST
			tmp->next->prev = head;
#endif
			free(tmp);
			return (head);
		}
		free(head);
	}
	return (NULL);
}

struct ll *ll_burn(struct ll *head)
{
	if (head)
		return (ll_burn(ll_del(head)));
	return (head);
}
