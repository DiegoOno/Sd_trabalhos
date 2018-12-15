#include "src/dht11/dht11.h"
#include "src/display_LCD/display_LCD.h"
#include <util/delay.h>
#include <stdlib.h>
#include "src/util/uart/uart.h"

#define DHT 2

int main() {
  char buffer[8];

  init_dht11(DHT);
  init_LCD();
  uart_init();
  print_LCD("Temp: ");
  cmd_LCD(0xC0,0);
  print_LCD("Umid: ");

  while(1) {
    read(DHT);
    cmd_LCD(0x86, 0);
    print_LCD(itoa(data[1], buffer, 10));
    cmd_LCD(0x89, 0);
    print_LCD("C");
    cmd_LCD(0xC6, 0);
    print_LCD(itoa(data[0], buffer, 10));
    cmd_LCD(0xC9, 0);
    print_LCD("%");
    _delay_ms(2000);
  }
}