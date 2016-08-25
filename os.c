#include <vxWorks.h>
#include <semLib.h>
#include <taskLib.h>

SEM_ID bs_tmr;

int tid_gps;
int tid_accs;
int tid_eots;
int tid_mls;
int tid_sync;

void os(void)
{
	bs_tmr = semBCreate(SEM_EMPTY, SEM_Q_PRIORITY);
	tid_gps = taskSpawn("gps", 100, VX_FP_TASK, 10000, (FUNCPTR)task_gps,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_accs = taskSpawn("accs", 110, VX_FP_TASK, 10000, (FUNCPTR)task_accs,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_eots = taskSpawn("eots", 120, VX_FP_TASK, 10000, (FUNCPTR)task_eots,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_mls = taskSpawn("mls", 130, VX_FP_TASK, 10000, (FUNCPTR)task_mls,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_sync = taskSpawn("sync", 140, VX_FP_TASK, 10000, (FUNCPTR)task_sync,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}
