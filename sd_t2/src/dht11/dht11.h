#include "../defines/defines.h"
#include "../io/io.h"
#include <math.h>

#define BITS 40
// data[0] -> Umidade; data[1] -> Temperatura; data[2] -> Checksum
extern int data[3];
extern int bit_vector[40];

void init_dht11(uint8_t pin);
void read(uint8_t pin);