all: runtest

runtest: main.o queue.o
	g++ -o runtest queue.o main.o
main.o: main.cpp
	g++ -c main.cpp
queue.o: queue.cpp
	g++ -c queue.cpp

clean:
	rm -rf *o runtest
