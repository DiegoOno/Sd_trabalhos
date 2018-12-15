CC = avr-gcc
CCOBJ = avr-objcopy

AVRDUDE = avrdude
ARVDUDE_CONF = /home/diego/arduino-1.8.5/hardware/tools/avr/etc/avrdude.conf
PORT = /dev/ttyACM0
BINARIES_PATH = binaries/
PROG = test

all: main

libraries:
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)io.o src/io/io.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)delay.o src/delay/delay.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)led.o src/led/led.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)button.o src/button/button.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)ultrasonic.o src/ultrasonic/ultrasonic.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)uart.o src/util/uart/uart.c
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(BINARIES_PATH)sevenSeg.o src/sevenSeg/sevenSeg.c

main:
	$(CC) -Os -mmcu=atmega328p -DF_CPU=16000000UL -c -o $(PROG).o $(PROG).c
	$(CC) -mmcu=atmega328p $(PROG).o -o $(PROG).elf $(BINARIES_PATH)io.o $(BINARIES_PATH)delay.o $(BINARIES_PATH)led.o $(BINARIES_PATH)button.o $(BINARIES_PATH)ultrasonic.o $(BINARIES_PATH)uart.o $(BINARIES_PATH)sevenSeg.o
	$(CCOBJ) -O ihex -R .eeprom $(PROG).elf $(PROG.hex)

clean:
	rm $(PROG).elf
	rm $(PROG).hex
	rm $(PROG).o

deploy:
	$(AVRDUDE) -V -C $(ARVDUDE_CONF) -p atmega328p -c arduino -P $(PORT) -b 115200 -D -Uflash:w:"$(PROG).elf":i
