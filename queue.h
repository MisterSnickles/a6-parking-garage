#pragma once

#include <vector>
#include <algorithm>

#include "car.h"

template <typename T> // T can be replaced with any symbol of your choice, U, K ...
                      // T stands for the type of data stored in the queue
                      // T must be the type of data stored in a Node
class Queue {
private:
    T* pArray;      // pointer to an array in heap that stores data whose type is T
                    // array is the underlying data structure ehind the data structure called Queue
               
    int capacity;   // the max size of the array
    int size;       // how many data items are actually stored in the array
    int front;      // the index of the first element
    int rear;       // the index of the last element

public:

    class QueueEmptyException{};
    class QueueFullException{};

    Queue() {
        std::cout << "\nQueue() called: " << this << std::endl;
        capacity = 20; // default capacity
        pArray = new T[capacity]; // allocate the array in the heap
                          // new DataType[size];
                          // T is the data type of each element in the array
        size = 0;
        front = 0;
        rear = capacity - 1;
    }

    Queue(int c) {
        std::cout << "\nQueue(int) called: " << this << std::endl;
        capacity = c;
        pArray = new T[capacity];
        size = 0;
        front = 0;
        rear = capacity - 1;
    }


    ~Queue() {
        std::cout << "\n~Queue() called: " << this << std::endl;
        // delete the entire list
        delete [] pArray;
        
    }


    void push(T data) {
        if (size == capacity)
            throw QueueFullException(); // throw ignores the remaining code in function : goes back to main() where push() is called

        rear = ++rear % capacity; // very first push() --> rear = 0
        pArray[rear] = data;
        size++;
    }

    T& peek() {
        if (size == 0)
            throw QueueEmptyException();

        return pArray[front];
    }

    void pop() 
    {
        if(size == 0) 
            throw QueueEmptyException();

        front = ++front % capacity;
        size--;
    }

    // output for arriving vehicles : using true bool flag passed to car.h printInfo(bool)
    void printArrivals() {
        if (size == 0) {
            std::cout << "No arriving cars." << std::endl;
            return;
        }
    
        std::cout << "================= PARKING =================" << std::endl;
        int count = 0;
        int index = front;
        while (count < size) {
            pArray[index].printInfo(true); // Show Arrival Time
            index = (index + 1) % capacity;
            count++;
        }
    }

    bool isEmpty() {
        return size == 0;
    }
    
    void printDepartures() {

        if (size == 0) {
            std::cout << "Empty" << std::endl;
            return;
        }
    
        std::vector<Car> cars;
        Queue<Car> tempQueue = *this; 
    
       
        while (!tempQueue.isEmpty()) {
            cars.push_back(tempQueue.peek());
            tempQueue.pop();
        }
    
        // using a sorting algorithm on temporary vector
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.departureTime < b.departureTime;
        });
    
        // output for departing vehicles : using false bool flag passed to car.h printInfo(bool)
        std::cout << "\n================= UNPARKING ==================" << std::endl;
        for (const auto& car : cars) {
            car.printInfo(false); // Show Departure Time
        }
    }

    int getSize() const {
        return size;
    }

};
