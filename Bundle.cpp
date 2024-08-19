#include "Bundle.hpp"
#include <iostream>
double Bundle::compute(double price){
    return price;
}
std::string BundleDecorator::getBundleName(){
    return this->getBundleName()+"__"+this->bundle->getBundleName();
}
double PercentageBundleDecorator::compute(double price){
    double totalPrice= this->bundle->compute(price);
    double discountPercent= totalPrice*0.15;
    return totalPrice- discountPercent;
}
double SubtractionBundleDecorator::compute(double price){
    double totalPrice= this->bundle->compute(price);
    return totalPrice>100? totalPrice-100 : totalPrice;
}
