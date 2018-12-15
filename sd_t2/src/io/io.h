#pragma once
#include <avr/io.h>
#include <avr/portpins.h>

enum pin_type { OUTPUT, INPUT, PULL_UP };
enum pin_state { LOW, HIGH };

void pinMode(uint8_t pinNumber, uint8_t pinType);
void digitalWrite(uint8_t pinNumber, uint8_t value);