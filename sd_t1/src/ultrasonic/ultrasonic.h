#include <avr/io.h>
#include <avr/portpins.h>

enum type{ECHO, TRIGGER};

void createUtrasonicPins(uint8_t triggerPin, uint8_t echoPin);
uint16_t calculateDistance(uint8_t triggerPin, uint8_t echoPin);