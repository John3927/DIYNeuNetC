CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

test: test.o node.o
	$(CC) $(CFLAGS) test.o node.o -o test

test.o: test.cpp activation.h node.h 
	$(CC) $(CFLAGS) -c test.cpp -lm

node.o: node.cpp activation.h node.h
	$(CC) $(CFLAGS) -c node.cpp -lm

clean:
	rm -f *.o test

