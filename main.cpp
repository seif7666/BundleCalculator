#include "Customer.hpp"
using namespace std;

int main(){
    Customer customer("Mohamed");
    for(int i=100;i>=0;i--){
        double input;
        cin>>input;
        customer.createOperation(input);
    }
    
    return 0;
}