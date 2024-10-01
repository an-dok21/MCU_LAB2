#ifndef INC_SEGMENT7DISPLAY_H_
#define INC_SEGMENT7DISPLAY_H_
#include "main.h"
#include "timer.h"
#define MAX_LED 4

void display7Segment(GPIO_TypeDef *GPIOx, uint8_t number, int gpioPin[7]);

/* Exercise 1
 * */
void displayHandler(int *num);
void displayPeriodLed(int num);

/* Exercise 2, 3, 4, 5, 6, 7, 8
 * */
void update7SEG(int index);
void updateClockBuffer(int* hourPtr, int* minPtr);
void digitalClock(int* hourPtr, int* minPtr, int* secPtr, int* idxPtr, int timerDuration);

/*Exercise 9, 10*/
/* Matrix Led 8x8
 * */
void clearAll();
void enableAllRows();
void enableAllCols();
void displayCol(int value);
void testingDisplayLedMatrix(int value);
void displayAnimation(int hexCode[8], int *idxHex, int duration);

#endif /* INC_SEGMENT7DISPLAY_H_ */
