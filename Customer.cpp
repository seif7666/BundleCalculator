#include "Customer.hpp"
#include "BundleFactory.hpp"
#include "logger.hpp"
using namespace std;

Customer::Customer(std::string name){
    this->name= name;
    this->numberOfOperations= 0;
    this->subscribedBundle=new Bundle();
}

void Customer::createOperation(double price){
    this->numberOfOperations++;
    Logger::getLogger()->info("This is operation number "+ to_string(this->numberOfOperations));
    this->subscribedBundle= BundleFactory::getBundle(numberOfOperations,this->subscribedBundle);
    Logger::getLogger()->info("Bundle to be used is "+ this->subscribedBundle->getBundleName());
    double result= this->subscribedBundle->compute(price);
    cout<<"Result of operation is "<<result <<endl;
    Logger::getLogger()->info("Operation Completed!");
}

string Customer::getName(){return name;}
string Customer::getStats(){
    return name+"\t"+to_string(numberOfOperations);
}
