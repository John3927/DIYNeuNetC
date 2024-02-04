CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

test: linalg.o test.o
	$(CC) $(CFLAGS) test.o linalg.o -o test

test.o: test.cpp linalg.h
	$(CC) $(CFLAGS) -c test.cpp 

node.o: node.cpp activation.h node.h
	$(CC) $(CFLAGS) -c node.cpp -lm

linalg.o: linalg.cpp linalg.h
	$(CC) $(CFLAGS) -c linalg.cpp 

clean:
	rm -f *.o test

