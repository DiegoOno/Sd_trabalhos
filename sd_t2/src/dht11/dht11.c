#include "dht11.h"

int data[3] = {0, 0, 0};
int bit_vector[BITS];

void init_dht11(uint8_t pin) {
  pinMode(pin, OUTPUT);
  _delay_ms(1000);
}

void read(uint8_t pin) {
  int count, j;
  pinMode(pin, OUTPUT);
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;

  digitalWrite(pin, HIGH);
  _delay_ms(2000);
  digitalWrite(pin, LOW);
  _delay_ms(20);
  digitalWrite(pin, HIGH);
  _delay_us(40);
  pinMode(pin, PULL_UP);
  _delay_us(170);

  for (int i = 0; i < BITS; i++) {
    count = 0;
    while (!IS_BIT_SET(PIND, pin))
      ;
    while (IS_BIT_SET(PIND, pin)) {
      count++;
      _delay_us(1);
    }
    if (count < 30) {
      bit_vector[i] = 0;
    } else {
      bit_vector[i] = 1;
    }
  }

  j = 0;
  while (j < 8) {
    data[0] += bit_vector[j] * pow(2, (7 - (j % 8)));
    j++;
  }
  j += 8;
  while (j < 24) {
    data[1] += bit_vector[j] * pow(2, (7 - (j % 8)));
    j++;
  }
  j += 8;
  while (j < 40) {
    data[2] += bit_vector[j] * pow(2, (7 - (j % 8)));
    j++;
  }
}
