#ifndef _LCD_H
#define _LCD_H

#include "../defines/defines.h"

#define DATA_LCD PORTD
#define nibble_data 1

#define CTRL_LCD PORTB
#define ENABLE PB0
#define RS PB1

#define tam_vector 5
#define conv_ascii 48

#define pulse_enable() _delay_us(1); SET_BIT(CTRL_LCD, ENABLE); _delay_us(1);  CLEAR_BIT(CTRL_LCD, ENABLE); _delay_us(45)

void init_LCD();
void cmd_LCD(unsigned char c, char cd);
void print_LCD(char *c);

#endif