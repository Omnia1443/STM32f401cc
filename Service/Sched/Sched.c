/*
 * Sched.c
 *
 *  Created on: 30 Mar 2023
 *      Author: Omnia
 */
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Systick.h"
#include "Sched.h"

typedef struct{
	runnable_t *runnable;
	u8 status;
	u32 remainTime_ms;
}runnableState_t;

static runnableState_t runnableState[MAX];

void Sched_vidInit(void)
{
	STK_vidInit();
	STK_enuCBF(Sched);
	STK_enuSetTickTime(TICK);
}

void Sched_vidStart(void)
{
	STK_vidStart();
	while(1);
}

void Sched_vidAddRunnable(runnable_t* Runnable)
{
	if(Runnable !=  NULL)
	{
		if(runnableState[Runnable->priority].runnable == NULL)
		{
			runnableState[Runnable->priority].runnable = Runnable;
			runnableState[Runnable->priority].remainTime_ms = Runnable->startDelay;
		}
	}
}

void Sched_vidPauseRunnable(u32 time, runnable_t* Runnable)
{
	runnableState[Runnable->priority].remainTime_ms += time;
}

void Sched(void)
{
	u8 idx;
	for(idx=0;idx<MAX;idx++)
	{
		if(runnableState[idx].runnable != NULL)
		{
			if(runnableState[idx].remainTime_ms == 0)
			{
				runnableState[idx].runnable->cbf();
				runnableState[idx].remainTime_ms = runnableState[idx].runnable->period_ms;
			}
			runnableState[idx].remainTime_ms -= TICK;
		}
	}
}
