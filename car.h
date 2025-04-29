#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Car {
public:
    int arrivalTime;
    int parkingDuration;
    int departureTime;
    std::string licensePlate;
    std::string carType;


    Car() : arrivalTime(0), parkingDuration(0), carType(""), licensePlate("") {}

    Car(int arrival, int duration, std::string type, std::string plate) {
        this->arrivalTime = arrival; // arrival time
        this->parkingDuration = duration; // duration of parking minutes
        this->departureTime = calculateDepartureTime(); // calculated using duration and arrival in calculateDepartureTime() in car.h
        this->licensePlate = plate; // license plate
        this->carType = type; // compact or truck
    }

    // print vehicle info : two types using bool flag, one for parked, and one for unparked
    void printInfo(bool showArrivals) const {
        if (showArrivals) {
            std::cout << "Park at " << std::setw(4) << std::setfill('0') << arrivalTime << "       ";
        } else {
            std::cout << "Unpark at " << std::setw(4) << std::setfill('0') << departureTime << "        ";
        }
            cout << licensePlate << "          "
            << std::setw(7) << std::setfill(' ') << carType << std::endl;
    }

    int calculateDepartureTime() {
        int hours = arrivalTime / 100;
        int min = arrivalTime % 100;

        int totalMin = hours * 60 + min + parkingDuration;
        int newHours = (totalMin / 60) % 24;
        int newMinutes = totalMin % 60;
        int departureTime = (newHours * 100) + newMinutes;
        return departureTime;
    }


};