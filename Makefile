CC=g++
CFLAGS=-Wall -g --std=c++11 -pedantic -Wextra -O2
OBJECTS=Selection-Algorithm.o ClostestPair-Algorithm.o Fibonacci-Algorithm.o RodCutting-Algorithm.o Knapsack-Algorithm.o PrettyPrinting-Algorithm.o BellmanFord-Algorithm.o Shuffle-Algorithm.o \
BinarySearch-Algorithm.o DFS-Algorithm.o MergeSort-Algorithm.o QuickSort-Algorithm.o
WIN_PATH=Executables/Windows
LINUX_PATH=Executables/Linux
MACOS_PATH=Executables/MacOS

# macOS architecture (Intel x86_64)
MACOS_ARCH = -arch x86_64

all-win: Selection-win ClostestPair-win Fibonacci-win RodCutting-win Knapsack-win PrettyPrinting-win BellmanFord-win Shuffle-win BinarySearch-win DFS-win MergeSort-win QuickSort-win
all-linux: Selection-linux ClostestPair-linux Fibonacci-linux RodCutting-linux Knapsack-linux PrettyPrinting-linux BellmanFord-linux Shuffle-linux BinarySearch-linux DFS-linux MergeSort-linux QuickSort-linux
all-macos: Selection-macos ClostestPair-macos Fibonacci-macos RodCutting-macos Knapsack-macos PrettyPrinting-macos BellmanFord-macos Shuffle-macos BinarySearch-macos DFS-macos MergeSort-macos QuickSort-macos
#Selection Algorithm
Selection-win: Selection-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Selection.exe Selection-Algorithm.o
Selection-linux: Selection-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/Selection Selection-Algorithm.o
Selection-macos: Selection-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/Selection Selection-Algorithm.o
Selection-Algorithm.o: Selection-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Selection-Algorithm.cpp

#ClostestPair Algorithm
ClostestPair-win: ClostestPair-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/ClostestPair.exe ClostestPair-Algorithm.o
ClostestPair-linux: ClostestPair-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/ClostestPair ClostestPair-Algorithm.o
ClostestPair-macos: ClostestPair-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/ClostestPair ClostestPair-Algorithm.o
ClostestPair-Algorithm.o: ClostestPair-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c ClostestPair-Algorithm.cpp

#Fibonacci Algorithm
Fibonacci-win: Fibonacci-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Fibonacci.exe Fibonacci-Algorithm.o
Fibonacci-linux: Fibonacci-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/Fibonacci Fibonacci-Algorithm.o
Fibonacci-macos: Fibonacci-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/Fibonacci Fibonacci-Algorithm.o
Fibonacci-Algorithm.o: Fibonacci-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Fibonacci-Algorithm.cpp

#RodCutting Algorithm
RodCutting-win: RodCutting-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/RodCutting.exe RodCutting-Algorithm.o
RodCutting-linux: RodCutting-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/RodCutting RodCutting-Algorithm.o
RodCutting-macos: RodCutting-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/RodCutting RodCutting-Algorithm.o
RodCutting-Algorithm.o: RodCutting-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c RodCutting-Algorithm.cpp

#Knapsack Algorithm
Knapsack-win: Knapsack-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Knapsack.exe Knapsack-Algorithm.o
Knapsack-linux: Knapsack-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/Knapsack Knapsack-Algorithm.o
Knapsack-macos: Knapsack-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/Knapsack Knapsack-Algorithm.o
Knapsack-Algorithm.o: Knapsack-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Knapsack-Algorithm.cpp

#PrettyPrinting Algorithm
PrettyPrinting-win: PrettyPrinting-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/PrettyPrinting.exe PrettyPrinting-Algorithm.o
PrettyPrinting-linux: PrettyPrinting-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/PrettyPrinting PrettyPrinting-Algorithm.o
PrettyPrinting-macos: PrettyPrinting-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/PrettyPrinting PrettyPrinting-Algorithm.o
PrettyPrinting-Algorithm.o: PrettyPrinting-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c PrettyPrinting-Algorithm.cpp

#BellmanFord Algorithm
BellmanFord-win: BellmanFord-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/BellmanFord.exe BellmanFord-Algorithm.o
BellmanFord-linux: BellmanFord-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/BellmanFord BellmanFord-Algorithm.o
BellmanFord-macos: BellmanFord-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/BellmanFord BellmanFord-Algorithm.o
BellmanFord-Algorithm.o: BellmanFord-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c BellmanFord-Algorithm.cpp

#Shuffle Algorithm
Shuffle-win: Shuffle-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/Shuffle.exe Shuffle-Algorithm.o
Shuffle-linux: Shuffle-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/Shuffle Shuffle-Algorithm.o
Shuffle-macos: Shuffle-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/Shuffle Shuffle-Algorithm.o
Shuffle-Algorithm.o: Shuffle-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c Shuffle-Algorithm.cpp

#BinarySearch Algorithm
BinarySearch-win: BinarySearch-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/BinarySearch.exe BinarySearch-Algorithm.o
BinarySearch-linux: BinarySearch-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/BinarySearch BinarySearch-Algorithm.o
BinarySearch-macos: BinarySearch-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/BinarySearch BinarySearch-Algorithm.o
BinarySearch-Algorithm.o: BinarySearch-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c BinarySearch-Algorithm.cpp

#DFS Algorithm
DFS-win: DFS-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/DFS.exe DFS-Algorithm.o
DFS-linux: DFS-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/DFS DFS-Algorithm.o
DFS-macos: DFS-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/DFS DFS-Algorithm.o
DFS-Algorithm.o: DFS-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c DFS-Algorithm.cpp

#MergeSort Algorithm
MergeSort-win: MergeSort-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/MergeSort.exe MergeSort-Algorithm.o
MergeSort-linux: MergeSort-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/MergeSort MergeSort-Algorithm.o
MergeSort-macos: MergeSort-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/MergeSort MergeSort-Algorithm.o
MergeSort-Algorithm.o: MergeSort-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c MergeSort-Algorithm.cpp

#QuickSort Algorithm
QuickSort-win: QuickSort-Algorithm.o
	$(CC) $(CFLAGS) -o $(WIN_PATH)/QuickSort.exe QuickSort-Algorithm.o
QuickSort-linux: QuickSort-Algorithm.o
	$(CC) $(CFLAGS) -o $(LINUX_PATH)/QuickSort QuickSort-Algorithm.o
QuickSort-macos: QuickSort-Algorithm.o
	$(CC) $(CFLAGS) $(MACOS_ARCH) -o $(MACOS_PATH)/QuickSort QuickSort-Algorithm.o
QuickSort-Algorithm.o: QuickSort-Algorithm.cpp
	$(CC) $(CFLAGS) -Wno-padded -c QuickSort-Algorithm.cpp

clean:
	rm -f $(OBJECTS) *~ *.gch
