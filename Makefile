CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

test: test.o network.o layer.o
	$(CC) $(CFLAGS) test.o network.o layer.o -o test

test.o: test.cpp network.h
	$(CC) $(CFLAGS) -c test.cpp 

network.o: network.h layer.h
	$(CC) $(CFLAGS) -c network.cpp -lm

layer.o: layer.h
	$(CC) $(CFLAGS) -c layer.cpp -lm

clean:
	rm -f *.o test

