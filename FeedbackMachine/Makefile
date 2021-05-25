CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example: RandomOSC.o analyser.o circBuffer.o threedelay.o jack_module.o main.o
				$(CC) -o $@ $(CFLAGS) RandomOSC.o analyser.o circBuffer.o threedelay.o  jack_module.o main.o $(LDFLAGS)

.cpp.o:
				$(CC) -c $< $(CFLAGS)

clean:
				rm -f *.o
				rm -f example
