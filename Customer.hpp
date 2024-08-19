#ifndef CUST_H
#define CUST_H
#include <iostream>
#include "Bundle.hpp"

#define NUM_OPERATION_FOR_FIRST_BUNDLE 3
class Customer{
    private:
        std::string name;
        int numberOfOperations;
        Bundle* subscribedBundle;
        void checkAvailableBundle();
    public:
        Customer(std::string customerName);
        void createOperation(double price);
        std::string getName();
};
#endif