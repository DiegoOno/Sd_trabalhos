#include "../io/io.h"
#include "../util/uart/uart.h"
#include "../delay/delay.h"

void createButton(uint8_t pinNumber);
uint8_t waitClick(uint8_t buttonPin);
uint8_t doNotWaitClick(uint8_t buttonPin);
uint8_t isPressed(uint8_t buttonPin);