#include <avr/io.h>
#include <avr/portpins.h>

void createLedPin(uint8_t pinNumber);
void turnLedOn(uint8_t pinNumber); 
void turnLedOff(uint8_t pinNumber);
void changeLedState(uint8_t pinNumber);
void blinkLed(uint8_t pinNumber, uint32_t ms_time); 