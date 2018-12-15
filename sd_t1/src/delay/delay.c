#define F_CPU 16000000UL
#include <util/delay.h> 

void delay_ms(uint32_t ms_time) {
    
    for(uint32_t i = 0; i < ms_time; i++) {
        asm volatile (
            "    ldi  r18, 21"	"\n"
            "    ldi  r19, 199"	"\n"
            "1:  dec  r19"	"\n"
            "    brne 1b"	"\n"
            "    dec  r18"	"\n"
            "    brne 1b"	"\n"
        );
    }
}

void delay_us(uint32_t us_time) {

    for(uint32_t i = 0; i < us_time; i++) {
        asm volatile (
            "    ldi  r18, 5"	"\n"
            "1:  dec  r18"	"\n"
            "    brne 1b"	"\n"
            "    nop"	"\n"
        );
    }
}