extern SEM_ID bs_tmr;
extern struct ll *current;
extern unsigned tick;
extern int com1;

struct ll *wr_sm(struct ll *p, char *ch, char *data, unsigned n);
