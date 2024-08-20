#include "Bundle.hpp"
#include <iostream>
#include "logger.hpp"
double Bundle::compute(double price){
    return price;
}
std::string Bundle::getBundleName(){
    return this->bundleName;
}
std::string BundleDecorator::getBundleName(){
    return Bundle::getBundleName()+"__"+this->bundle->getBundleName();
}
double PercentageBundleDecorator::compute(double price){
    Logger::getLogger()->debug("Entering method compute in PercentageBundleDecorator");
    double totalPrice= this->bundle->compute(price);
    double discountPercent= totalPrice*0.15;
    Logger::getLogger()->info("Percentage: The price "+std::to_string(totalPrice)+ " has become "+std::to_string(totalPrice- discountPercent) +" after discount");
    Logger::getLogger()->debug("Exiting method compute in PercentageBundleDecorator");
    return totalPrice- discountPercent;
}
double SubtractionBundleDecorator::compute(double price){
    Logger::getLogger()->debug("Entering method compute in SubtractionBundleDecorator");
    double totalPrice= this->bundle->compute(price);
    Logger::getLogger()->info("Subtraction: The price "+std::to_string(totalPrice)+ " has become "+std::to_string(totalPrice>100? totalPrice-100 : totalPrice) +" after discount");
    Logger::getLogger()->debug("Exiting method compute in SubtractionBundleDecorator");
    return totalPrice>100? totalPrice-100 : totalPrice;
}
