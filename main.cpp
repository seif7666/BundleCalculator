#include "Bundle.hpp"


int main(){
    PercentageBundleDecorator percBundle;
    std::cout<<percBundle.compute(150)<<std::endl;
    std::cout<<percBundle.getBundleName()<<std::endl;
    return 0;
}