CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g $(shell pkg-config --cflags libusb-1.0)
LDFLAGS = $(shell pkg-config --libs libusb-1.0)

# File oggetto da compilare
OBJS = main.o check-device.o

# Target principale
main: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Regole implicite per i .o
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

# Pulizia
clean:
	rm -f *.o main

