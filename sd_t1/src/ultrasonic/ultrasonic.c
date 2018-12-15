#include <avr/io.h>
#include <avr/portpins.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "../io/io.h"
#include "../macros/macros.h"


enum type{ECHO, TRIGGER};

void createUtrasonicPins(uint8_t triggarPin, uint8_t echoPin) {
    pinMode(triggarPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

uint16_t calculateDistance(uint8_t triggerPin, uint8_t echoPin) {
    uint32_t duration = 0;

    SET_BIT(TCCR1B, CS01);

    digitalWrite(triggerPin, HIGH);
    _delay_us(10);
    digitalWrite(triggerPin, LOW);

    if(echoPin >= 0 && echoPin <= 7) {
        while(!TST_BIT(PIND, echoPin % 8));
        TCNT1 = 0;
        while (TST_BIT(PIND, echoPin % 8));
        duration = TCNT1;
    } else {
        if(echoPin >= 8 && echoPin <= 13) {
            while(!TST_BIT(PINB, echoPin % 8));
            TCNT1 = 0;
            while (TST_BIT(PINB, echoPin % 8)); 
            duration = TCNT1;        
        } else {
            if(echoPin >= 14 && echoPin <= 19) {
                while(!TST_BIT(PINC, echoPin % 7));
                TCNT1 = 0;
                while (TST_BIT(PINC, echoPin % 7));
                duration = TCNT1;        
            }
        }
    }
    digitalWrite(echoPin, LOW);
    return duration / 116;
}