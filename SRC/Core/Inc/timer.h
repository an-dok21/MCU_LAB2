#ifndef INC_TIMER_H_
#define INC_TIMER_H_

/*Basic timer's counter*/
extern int timerFlag;
void setTimer(int duration);
void timerRun();

/*Exercise 2, 3, 4, 5, 6, 7, 8: Double Led's timer*/
extern int doubleLedFlag;
void setLedTimer(int duration);

#endif /* INC_TIMER_H_ */
