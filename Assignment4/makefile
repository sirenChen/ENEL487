all: crcTest
crcTest: main.o crc.o
	g++ -o crcTest crc.o main.o
main.o: main.c
	g++ -c main.c
crc.o: crc.c
	g++ -c crc.c
clean:
	rm -rf *o crcTest
