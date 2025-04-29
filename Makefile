parking-garage.exe: main.o
	g++ -o parking-garage.exe main.cpp

main.o: main.cpp car.h queue.h
	g++ -g -c main.cpp

clean:
	rm *.o *.exe
r:
	./parking-garage.exe