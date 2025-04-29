#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

#include "queue.h"
#include "car.h"

int main() {

    Queue<Car> arrivingCars; // stores car objects
    
    string line;
    fstream fin;

    // opening in read mode : validating file opening
    fin.open("park-101923.txt", ios::in);
    if(!fin.is_open()) {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    // read from file : store variables arrival, duration, type, plate : construct car object from those variables
    // depatureTime is calculated during car object construction
    while(getline(fin, line)) {
        stringstream ss(line);
        int arrival, duration;
        string type, plate;

        if(ss >> arrival >> duration >> type >> plate) {
            arrivingCars.push(Car(arrival, duration, type, plate));
        }
    }

    // close file
    fin.close();


    // print arriving cars
    arrivingCars.printArrivals();

    // print amount of cars parked : queue.h line 80
    cout << "\nCars parked: " << arrivingCars.getSize() << endl;

    // readability
    cout << endl;

    // print departing cars : queue.h line 101
    arrivingCars.printDepartures();


    
    return 0;
}
