CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

test: test.o layer.o network.o
	$(CC) $(CFLAGS) test.o layer.o network.o -o test

test.o: test.cpp network.h
	$(CC) $(CFLAGS) -c test.cpp 

network.o: network.h layer.h network.cpp
	$(CC) $(CFLAGS) -c network.cpp -lm

layer.o: layer.h layer.cpp
	$(CC) $(CFLAGS) -c layer.cpp -lm

clean:
	rm -f *.o test

