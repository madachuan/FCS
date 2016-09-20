#include <vxWorks.h>
#include <semLib.h>
#include <msgQLib.h>
#include <taskLib.h>

SEM_ID bs_tmr;

MSG_Q_ID mq_can;

int tid_can;
int tid_gps;
int tid_accs;
int tid_eots;
int tid_mls;
int tid_sync;

void os(void)
{
	bs_tmr = semBCreate(SEM_EMPTY, SEM_Q_PRIORITY);
	mq_can = msgQCreate(1, 13, MSG_Q_PRIORITY);
	tid_can = taskSpawn("can", 100, VX_FP_TASK, 10000, (FUNCPTR)task_can,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_gps = taskSpawn("gps", 110, VX_FP_TASK, 10000, (FUNCPTR)task_gps,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_accs = taskSpawn("accs", 120, VX_FP_TASK, 10000, (FUNCPTR)task_accs,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_eots = taskSpawn("eots", 130, VX_FP_TASK, 10000, (FUNCPTR)task_eots,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_mls = taskSpawn("mls", 140, VX_FP_TASK, 10000, (FUNCPTR)task_mls,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	tid_sync = taskSpawn("sync", 150, VX_FP_TASK, 10000, (FUNCPTR)task_sync,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}
