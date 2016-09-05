#define DUAL_LINKED_LIST

struct ll {
	void *key;
	struct ll *next;
#ifdef DUAL_LINKED_LIST
	struct ll *prev;
#endif
};
