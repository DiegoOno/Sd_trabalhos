#define F_CPU 16000000UL
#include <util/delay.h>
#include "../io/io.h"
#include "../util/uart/uart.h"
#include "../macros/macros.h"

enum boolean {FALSE, TRUE};

void createButton(uint8_t pinNumber) {
    pinMode(pinNumber, PULL_UP);
}

uint8_t waitClick(uint8_t buttonPin) {
    if(buttonPin >= 0 && buttonPin <= 7) {
        if(!TST_BIT(PIND, buttonPin % 8)) {
            while(!TST_BIT(PIND, buttonPin % 8));
            _delay_ms(10);
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        if(buttonPin >= 8 && buttonPin <= 13) {
            if(!TST_BIT(PINB, buttonPin % 8)) {
                while(!TST_BIT(PINB, buttonPin % 8));
                _delay_ms(10);
                return TRUE;
            } else {
                return FALSE;
            }
        } else {
            if(buttonPin >= 14 && buttonPin <= 19) {
                if(!TST_BIT(PINC, buttonPin % 8)) {
                    while(!TST_BIT(PINC, buttonPin % 7));
                    _delay_ms(10);
                    return TRUE;
                } else {
                    return FALSE;
                }
            }
        }
    }
}

uint8_t doNotWaitClick(uint8_t buttonPin) {
    if(buttonPin >= 0 && buttonPin <= 7) {
        if(!TST_BIT(PIND, buttonPin % 8)) {
            _delay_ms(20);
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        if(buttonPin >= 8 && buttonPin <= 13) {
            if(!TST_BIT(PINB, buttonPin % 8)) {
                _delay_ms(20);
                return TRUE;
            } else {
                return FALSE;
            }
        } else {
            if(buttonPin >= 14 && buttonPin <= 19) {
                if(!TST_BIT(PINC, buttonPin % 7)) {
                    _delay_ms(20);
                    return TRUE;
                } else {
                    return FALSE;
                }
            }
        }
    }
}

uint8_t isPressed(uint8_t buttonPin) {
    if(buttonPin >= 0 && buttonPin <= 7) {
        if(!TST_BIT(PIND, buttonPin % 8)) {
            _delay_ms(50);
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        if(buttonPin >= 8 && buttonPin <= 13) {
            if(!TST_BIT(PINB, buttonPin % 8)) {
                _delay_ms(50);
                return TRUE;
            } else {
                return FALSE;
            }
        } else {
            if(buttonPin >= 14 && buttonPin <= 19) {
                if(!TST_BIT(PINC, buttonPin % 7)) {
                    _delay_ms(50);
                    return TRUE;
                } else {
                    return FALSE;
                }
            }
        }
    }
}