#include <avr/io.h>
#include <avr/portpins.h>
#include "../macros/macros.h"
#include "../io/io.h"
#include "../delay/delay.h"

void createLedPin(uint8_t pinNumber) {
    pinMode(pinNumber, OUTPUT);
}

void turnLedOn(uint8_t pinNumber) {
    digitalWrite(pinNumber, HIGH);
} 

void turnLedOff(uint8_t pinNumber) {
    digitalWrite(pinNumber, LOW);
}

void changeLedState(uint8_t pinNumber) {
    if(pinNumber >= 0 && pinNumber <= 7) {
        SWT_BIT(PORTD, pinNumber % 8);
    } else {
        if(pinNumber >= 8 && pinNumber <= 13) {
            SWT_BIT(PORTB, pinNumber % 8);
        } else {
            if(pinNumber >= 14 && pinNumber <= 19) {
                SWT_BIT(PORTC, pinNumber % 8);
            }
        }
    }
}

void blinkLed(uint8_t pinNumber, uint32_t ms_time) {
    turnLedOn(pinNumber);
    delay_ms(ms_time);
    turnLedOff(pinNumber);
    delay_ms(ms_time);
} 