#include <avr/io.h>
#include <avr/portpins.h>

enum type{ANODO, CATODO};

void clearAll(uint8_t pins[], uint8_t display_type);

void createSevenSegPins(uint8_t pins[]);

void selectHex(uint8_t pins[], char character, uint8_t display_type);

void writeHex(uint8_t pins[], const char character[], uint8_t display_type);

