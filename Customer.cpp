#include "Customer.hpp"
using namespace std;

Customer::Customer(std::string name){
    this->name= name;
    this->numberOfOperations= 0;
    this->subscribedBundle=new Bundle();
}

void Customer::createOperation(double price){
    this->numberOfOperations++;
    //TODO
    double result= this->subscribedBundle->compute(price);
}

string Customer::getName(){return this->getName();}

