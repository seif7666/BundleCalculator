#include "Customer.hpp"
#include "BundleFactory.hpp"
using namespace std;

Customer::Customer(std::string name){
    this->name= name;
    this->numberOfOperations= 0;
    this->subscribedBundle=new Bundle();
}

void Customer::createOperation(double price){
    this->numberOfOperations++;
    this->subscribedBundle= BundleFactory::getBundle(numberOfOperations,this->subscribedBundle);
    double result= this->subscribedBundle->compute(price);
    cout<<"Result of operation is "<<result <<endl;
}

string Customer::getName(){return this->getName();}

