#include "Customer.hpp"
#include <unordered_map>
#include <vector>
#include "logger.hpp"
using namespace std;

class Main{
    private:
        vector<string> customerNames;
    public:
        unordered_map<string,Customer*> customers;
        void addNewCustomer(Customer* cust){
            cout<<cust->getName()<<endl;
            if(customers.find(cust->getName())==customers.end()){
                customers[cust->getName()]= cust;
                customerNames.push_back(cust->getName());
            }
            else{
                cout<<"Customer already exists!"<<endl;
                delete cust;
            }
        }
        void createOperation(Customer* customer, double price){
            customer->createOperation(price);
        }

        string printCustomers(){
            for(int i= 0;i<customerNames.size();i++){
                cout<<(i+1)<<" : "<<customers[customerNames[i]]->getStats()<<endl;
            }
            int index;
            cin>>index;
            index= (index-1) % customerNames.size();
            return customerNames[index];
        }
};

int main(){
    Main main;
    Logger* logger= Logger::getLogger();
    logger->info("Hello World!");

    /*
    while(true){
        cout<<"1: Create Customer\n2: Create Operation"<<endl;
        int input;
        cin>>input;
        if(input ==1){
            string name;
            cout<<"Enter name: ";
            cin>>name;
            main.addNewCustomer(new Customer(name));
        }
        else if(input==2){
            double price;
            cout<<"Enter price: ";
            cin>>price;
            main.createOperation(main.customers[main.printCustomers()],price);
        }
    }*/
    
    return 0;
}