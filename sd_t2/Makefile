CC = avr-gcc
CCOBJ = avr-objcopy

AVRDUDE = avrdude
ARVDUDE_CONF = /home/diego/arduino-1.8.7/hardware/tools/avr/etc/avrdude.conf
PORT = /dev/ttyACM1
BINARIES_PATH = Binaries/
PROG = main
SRC_PATH = src/

all: main

libraries:
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)io.o $(SRC_PATH)io/io.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)uart.o $(SRC_PATH)util/uart/uart.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)dht11.o $(SRC_PATH)dht11/dht11.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)display_LCD.o $(SRC_PATH)display_LCD/display_LCD.c

main:
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(PROG).o $(PROG).c 
	$(CC) -mmcu=atmega328p $(PROG).o -o $(PROG).elf $(BINARIES_PATH)io.o $(BINARIES_PATH)uart.o $(BINARIES_PATH)dht11.o $(BINARIES_PATH)display_LCD.o 
	$(CCOBJ) -O ihex -R .eeprom $(PROG).elf $(PROG.hex)

clean:
	rm $(PROG).elf
	rm $(PROG).hex
	rm $(PROG).o

deploy:
	$(AVRDUDE) -V -C $(ARVDUDE_CONF) -p atmega328p -c arduino -P $(PORT) -b 115200 -D -Uflash:w:"$(PROG).elf":i
