CC=g++
CFLAGS=-Wall -g --std=c++11 -pedantic -Wextra -O2
OBJECTS=Selection-Algorithm.o ClostestPair-Algorithm.o Fibonacci-Algorithm.o RodCutting-Algorithm.o Knapsack-Algorithm.o PrettyPrinting-Algorithm.o BellmanFord-Algorithm.o
WIN_PATH=Executables/Windows

all: Selection-win ClostestPair-win Fibonacci-win RodCutting-win Knapsack-win PrettyPrinting-win BellmanFord-win

Selection-win: Selection-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Selection.exe Selection-Algorithm.o

Selection-Algorithm.o: Selection-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Selection-Algorithm.cpp

ClostestPair-win: ClostestPair-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/ClostestPair.exe ClostestPair-Algorithm.o

ClostestPair-Algorithm.o: ClostestPair-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c ClostestPair-Algorithm.cpp

Fibonacci-win: Fibonacci-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Fibonacci.exe Fibonacci-Algorithm.o

Fibonacci-Algorithm.o: Fibonacci-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Fibonacci-Algorithm.cpp

RodCutting-win: RodCutting-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/RodCutting.exe RodCutting-Algorithm.o

RodCutting-Algorithm.o: RodCutting-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c RodCutting-Algorithm.cpp

Knapsack-win: Knapsack-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Knapsack.exe Knapsack-Algorithm.o

Knapsack-Algorithm.o: Knapsack-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Knapsack-Algorithm.cpp

PrettyPrinting-win: PrettyPrinting-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/PrettyPrinting.exe PrettyPrinting-Algorithm.o

PrettyPrinting-Algorithm.o: PrettyPrinting-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c PrettyPrinting-Algorithm.cpp

BellmanFord-win: BellmanFord-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/BellmanFord.exe BellmanFord-Algorithm.o

BellmanFord-Algorithm.o: BellmanFord-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c BellmanFord-Algorithm.cpp
clean:
	rm -f $(OBJECTS) *~ *.gch
