#include "timer.h"

/* Basic timer
 * */
int timerFlag = 0;
int timerCnt = 0;

void setTimer(int duration) {
	timerCnt = duration;
	timerFlag = 0;
}

void timerRun() {
	if (timerCnt > 0) {
		timerCnt--;
		if (timerCnt <= 0) {
			timerFlag = 1;
		}
	}
}
