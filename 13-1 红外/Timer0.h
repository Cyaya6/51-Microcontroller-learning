#ifndef __TIMER0_H__
#define __TIMER0_H__

void Timer0Init();
void Timer0_Run(unsigned char Flag);
unsigned int TimerGetCount();
void Timer0_SetCounter(unsigned int Value);
#endif