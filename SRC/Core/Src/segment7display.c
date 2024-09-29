#include "segment7display.h"

/* Helper function for 7 segment led.
 * */
int seg7Pin[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};
int seg7Pin2[] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14};
int ledStateArray[] = {0, 0, 0, 0, 0, 0, 0};


int convertBinChar(char bin) {
	return (bin == '1') ? 1 : 0;
}

int* convertState(char* stateStr, int count) {
	for (int i = 0; i < count; i++) {
		ledStateArray[i] = 0;
	}
	int *result = ledStateArray;
	for (int i = 0; i < count; i++) {
		result[i] = convertBinChar(stateStr[i]);
	}
	return result;
}

void display(GPIO_TypeDef *GPIOx, int gpios[7], char* stateStr) {
	int* states = convertState(stateStr, 7);
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOx, gpios[i], states[i]);
	}
}

void display7Segment(GPIO_TypeDef *GPIOx, uint8_t number, int gpioPin[7]) {
	switch (number) {
	case 0:
		display(GPIOx, gpioPin, "0000001");
		break;
	case 1:
		display(GPIOx, gpioPin, "1001111");
		break;
	case 2:
		display(GPIOx, gpioPin, "0010010");
		break;
	case 3:
		display(GPIOx, gpioPin, "0000110");
		break;
	case 4:
		display(GPIOx, gpioPin, "1001100");
		break ;
	case 5:
		display(GPIOx, gpioPin, "0100100");
		break;
	case 6:
		display(GPIOx, gpioPin, "0100000");
		break ;
	case 7:
		display(GPIOx, gpioPin, "0001111");
		break;
	case 8:
		display(GPIOx, gpioPin, "0000000");
		break;
	case 9:
		display(GPIOx, gpioPin, "0000100");
		break;
	default:
		break;
	}
}

/* Exercise1
 * */
void displayHandler(int* num) {
	if (timerFlag == 1) {
		displayPeriodLed(*num);
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(50);
		if (*num == 1) {
			*num = 2;
		} else {
			*num = 1;
		}
	}
}
void displayPeriodLed(int num) {
	if (num == 1) {
		HAL_GPIO_WritePin(GPIOA, ENABLE0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, ENABLE1_Pin, SET);
		display7Segment(GPIOB, 1, seg7Pin);
	} else {
		HAL_GPIO_WritePin(GPIOA, ENABLE0_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, ENABLE1_Pin, RESET);
		display7Segment(GPIOB, 2, seg7Pin);
	}
}




