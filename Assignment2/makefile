all: runtest
runtest: main.o ComplexNumber.o
	g++ -o runtest ComplexNumber.o main.o
main.o: main.c
	g++ -c main.c
ComplexNumber.o: ComplexNumber.c
	g++ -c ComplexNumber.c
clean:
	rm -rf *o runtest
