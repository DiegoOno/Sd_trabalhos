#include "display_LCD.h"

void init_LCD() {
  DDRD = 0xFF;
  DDRB = 0xFF;
  
  CLEAR_BIT(CTRL_LCD, RS); 
  CLEAR_BIT(CTRL_LCD, ENABLE); 
  _delay_ms(20);

  #if (nibble_data)
    DATA_LCD = (DATA_LCD & 0x0F) | 0x30;
  #else
    DATA_LCD = (DATA_LCD & 0xF0) | 0x03;
  #endif
  pulse_enable();
  _delay_ms(5);
  pulse_enable();
  _delay_us(200);
  pulse_enable();

  #if (nibble_data)
    DATA_LCD = (DATA_LCD & 0x0F) | 0x20;
  #else
    DATA_LCD = (DATA_LCD & 0xF0) | 0x02;
  #endif
  pulse_enable();
  cmd_LCD(0x28, 0);
  cmd_LCD(0x08, 0); 
  cmd_LCD(0x01, 0); 
  cmd_LCD(0x0C, 0); 
  cmd_LCD(0x80, 0); 
}

void cmd_LCD(unsigned char c, char cd) {
  if (cd == 0)
    CLEAR_BIT(CTRL_LCD, RS);
  else
    SET_BIT(CTRL_LCD, RS);

  #if (nibble_data) 
    DATA_LCD = (DATA_LCD & 0x0F) | (0xF0 & c);
  #else
    DATA_LCD = (DATA_LCD & 0xF0) | (c >> 4);
  #endif
  pulse_enable();

  #if (nibble_data)
    DATA_LCD = (DATA_LCD & 0x0F) | (0xF0 & (c << 4));
  #else
    DATA_LCD = (DATA_LCD & 0xF0) | (0x0F & c);
  #endif

  pulse_enable();
  if ((cd == 0) && (c << 4))
    _delay_ms(2);
}

void print_LCD(char *c) {
  for (; *c != 0; c++) cmd_LCD(*c, 1);
}