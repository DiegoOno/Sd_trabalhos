#include <avr/io.h>
#include <avr/portpins.h>
#include "../io/io.h"
#include "sevenSeg.h"
                       //abcdefg 
const char zero[]     = "1111110";
const char one[]      = "0110000";
const char two[]      = "1101101";
const char three[]    = "1111001";
const char four[]     = "0110011";
const char five[]     = "1011011";
const char six[]      = "1011111";
const char seven[]    = "1110000";
const char eight[]    = "1111111";
const char nine[]     = "1111011";
const char a[]        = "1111101";
const char b[]        = "0011111";
const char c[]        = "0001101";
const char d[]        = "0111101";
const char e[]        = "1101111";
const char f[]        = "1000111";  

void clearAll(uint8_t pins[], uint8_t display_type) {
    if(display_type == ANODO) {
        for(int i = 0; i < 7; i++) {
            digitalWrite(pins[i], HIGH);
        }
    } else {
        if(display_type == CATODO) {
            for(int i = 0; i < 7; i++) {
                digitalWrite(pins[i], LOW);
            }   
        }
    }
    
}    

void createSevenSegPins(uint8_t pins[]) {

    for(int i = 0; i < 7; i++) {
        pinMode(pins[i], OUTPUT);
    }
}

void writeHex(uint8_t pins[], const char character[], uint8_t display_type) {
   if(display_type == ANODO) {
        for(int i = 0; i < 7; i++) {
            if(character[i] == '0') {
                digitalWrite(pins[i], HIGH);
            } else {
                if(character[i] == '1') {
                    digitalWrite(pins[i], LOW);
                }
            }
        }
   } else {
       if(display_type == CATODO) {
            for(int i = 0; i < 7; i++) {
                if(character[i] == '0') {
                    digitalWrite(pins[i], LOW);
                } else {
                    if(character[i] == '1') {
                        digitalWrite(pins[i], HIGH);
                    }
                }
            }
       }
   }
}

void selectHex(uint8_t pins[], char character, uint8_t display_type) {  

    clearAll(pins, display_type);
    if(character == '0')
        writeHex(pins, zero, display_type);
    if(character == '1')
        writeHex(pins, one, display_type);
    if(character == '2')
        writeHex(pins, two, display_type);
    if(character == '3')
        writeHex(pins, three, display_type);
    if(character == '4')
        writeHex(pins, four, display_type);
    if(character == '5')
        writeHex(pins, five, display_type);
    if(character == '6')
        writeHex(pins, six, display_type);
    if(character == '7')
        writeHex(pins, seven, display_type);
    if(character == '8')
        writeHex(pins, eight, display_type);
    if(character == '9')
        writeHex(pins, nine, display_type);
    if(character == 'a')
        writeHex(pins, a, display_type);
    if(character == 'b')
        writeHex(pins, b, display_type);
    if(character == 'c')
        writeHex(pins, c, display_type);
    if(character == 'd')
        writeHex(pins, d, display_type);
    if(character == 'e')
        writeHex(pins, e, display_type);
    if(character == 'f')
        writeHex(pins, f, display_type);
}
