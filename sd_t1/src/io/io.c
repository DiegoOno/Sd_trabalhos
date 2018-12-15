#include <avr/io.h>
#include <avr/portpins.h>
#include "../macros/macros.h"

enum type {OUTPUT, INPUT, PULL_UP};
enum energy{LOW, HIGH};

void pinMode(uint8_t pinNumber, uint8_t pinType) {
    if(pinNumber >= 0 && pinNumber <= 7) {
        if(pinType == INPUT) {
            CLEAR_BIT(DDRD, pinNumber % 8);
        } else {
            if(pinType == OUTPUT) {
                SET_BIT(DDRD, pinNumber % 8);
            } else {
                if(pinType == PULL_UP) {
                    CLEAR_BIT(DDRD, pinNumber % 8);
                    SET_BIT(PORTD, pinNumber % 8);
                } 
            }
        }
    } else {
        if(pinNumber > 7 && pinNumber <= 13) {
            if(pinType == INPUT) {
                CLEAR_BIT(DDRB, pinNumber % 8);
            } else {
                if(pinType == OUTPUT) {
                    SET_BIT(DDRB, pinNumber % 8);
                } else {
                    if(pinType == PULL_UP) {
                        CLEAR_BIT(DDRB, pinNumber % 8);
                        SET_BIT(PORTB, pinNumber % 8);
                    } 
                }
            }
        } else {
            if (pinNumber >= 14 && pinNumber <= 19) {
                if(pinType == INPUT) {
                    CLEAR_BIT(DDRC, pinNumber % 7);
                } else {
                    if(pinType == OUTPUT) {
                        SET_BIT(DDRC, pinNumber % 7);
                    } else {
                        if(pinType == PULL_UP) {
                            CLEAR_BIT(DDRC, pinNumber % 7);
                            SET_BIT(PORTC, pinNumber % 7);
                        }
                    }
                }
            }
        }
    }
}

void digitalWrite(uint8_t pinNumber, uint8_t value) {
    if(pinNumber >= 0 && pinNumber <= 7) {
        if(value == HIGH) {
            SET_BIT(PORTD, pinNumber % 8);
        } else {
            if(value == LOW) {
                CLEAR_BIT(PORTD, pinNumber % 8);
            }
        }
    } else {
        if(pinNumber > 7 && pinNumber <= 13) {
            if(value == HIGH) {
                SET_BIT(PORTB, pinNumber % 8);
            } else {
                if(value == LOW) {
                    CLEAR_BIT(PORTB, pinNumber % 8);
                }
            }
        } else {
            if(pinNumber >= 14 && pinNumber <= 19) {
                if(value == HIGH) {
                    SET_BIT(PORTC, pinNumber % 7);
                } else {
                    if (value == LOW) {
                        CLEAR_BIT(PORTC, pinNumber % 7);
                    }
                }
            }
        }
    }
}

uint8_t readPin(uint8_t pinNumber) {
    if(pinNumber >= 0 && pinNumber <= 7) {
        if(!TST_BIT(DDRD, pinNumber % 8)) {
            return TST_BIT(PORTD, pinNumber % 8);
        }
    } else {
        if(pinNumber >= 8 && pinNumber <= 13) {
            if(!TST_BIT(DDRB, pinNumber % 8)) {
                return TST_BIT(PORTB, pinNumber % 8);
            } 
        } else {
            if(pinNumber >= 14 && pinNumber <= 19) {
                if(!TST_BIT(DDRC, pinNumber % 7)) {
                    return TST_BIT(PORTC, pinNumber % 7);
                }
            }
        }
    }
}