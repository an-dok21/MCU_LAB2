#ifndef INC_SEGMENT7DISPLAY_H_
#define INC_SEGMENT7DISPLAY_H_
#include "main.h"
#include "timer.h"
void display7Segment(GPIO_TypeDef *GPIOx, uint8_t number, int gpioPin[7]);

/* Exercise1
 * */
void displayHandler(int *num);
void displayPeriodLed(int num);

#endif /* INC_SEGMENT7DISPLAY_H_ */
