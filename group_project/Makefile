main: main.o addional.o
	g++ main.o addional.o -o main

main.o: main.cpp
	g++ -c main.cpp

addional.o: addional.cpp addional.h
	g++ -c addional.cpp

clean:
	rm *.o output
