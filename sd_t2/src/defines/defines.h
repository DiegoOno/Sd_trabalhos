#ifndef _MAIN_DEF_H
#define _MAIN_DEF_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

// Macros
// Change the state of the bit
#define SWT_BIT(REG, POS) (REG ^= (1 << POS))

// Set 1
#define SET_BIT(REG, POS) (REG |= (1 << POS))

// Set 0
#define CLEAR_BIT(REG, POS) (REG &= ~(1 << POS))

// Compare if the bit is one
#define IS_BIT_SET(REG, N) ((1 << (N) & (REG)) ? 1 : 0)
#endif