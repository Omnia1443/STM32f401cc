/*
 * Sched.h
 *
 *  Created on: 30 Mar 2023
 *      Author: Omnia
 */

#ifndef SCHED_H_
#define SCHED_H_


#define MAX		2
#define TICK	1

typedef void(*runnableCbf_t)(void);

typedef struct{
	u8* 			name;
	u8 				priority;
	u32 			period_ms;
	u32 			startDelay;
	runnableCbf_t 	cbf;
}runnable_t;

void Sched_vidInit(void);

void Sched_vidStart(void);

void Sched_vidAddRunnable(runnable_t* Runnable);

void Sched_vidPauseRunnable(u32 time, runnable_t* Runnable);

static void Sched(void);


#endif /* SCHED_H_ */
