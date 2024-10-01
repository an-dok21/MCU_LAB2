#include "timer.h"

#define TIMER_CYCLE 10

/* Basic timer
 * */
int timerFlag = 0;
int timerCnt = 0;

int doubleLedFlag = 0;
int doubleLedCounter = 0;

int matrixLedFlag = 0;
int matrixLedCounter = 0;

void setTimer(int duration) {
	timerCnt = duration;
	timerFlag = 0;
}


/* Exercise 2, 3, 4, 5, 6, 7, 8: Double led's timer
 * */
void setLedTimer(int duration) {
	doubleLedCounter = duration;
	doubleLedFlag = 0;
}

/*Exercise 9, 10*/
void setMatrixLedTimer(int duration) {
	matrixLedCounter = duration;
	matrixLedFlag = 0;
}


void timerRun() {
	/*Basic Timer*/
	if (timerCnt > 0) {
		timerCnt--;
		if (timerCnt <= 0) {
			timerFlag = 1;
		}
	}

	/*Double led's timer*/
	if (doubleLedCounter > 0) {
		doubleLedCounter--;
		if (doubleLedCounter <= 0) {
			doubleLedFlag = 1;
		}
	}

	/*Matrix Led Timer*/
	if (matrixLedCounter > 0) {
		matrixLedCounter--;
		if (matrixLedCounter <= 0) {
			matrixLedFlag = 1;
		}
	}
}
