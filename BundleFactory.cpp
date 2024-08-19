#include "BundleFactory.hpp"
#include <iostream>
using namespace std;


Bundle* getBundleFromInput(Bundle* bundles[], int length){
    for(int i=1;i<=length;i++)
        cout<<i<<": "<<bundles[i-1]->getBundleName()<<endl;
    int input;
    cin>>input;
    input--;
    Bundle* required;
    for(int i= 0;i<length;i++){
        if(i==input)
            required= bundles[i];
        else
            delete bundles[i];
    }
    return required;
}

Bundle* BundleFactory::getBundle(int numberOfOperations, Bundle* currentBundle){
    if(numberOfOperations<NUM_OPERATION_FOR_FIRST_BUNDLE)
        return currentBundle;
    if(numberOfOperations==NUM_OPERATION_FOR_FIRST_BUNDLE){
        delete currentBundle;
        return new SubtractionBundleDecorator();
    }
    if(numberOfOperations>=NUM_OPERATION_FOR_SECOND_STAGE && numberOfOperations<STAGE_THREE){
        delete currentBundle;
        cout<<"You have now reached "<<numberOfOperations<<" operations you can either pick on of these bundles!\n";
        Bundle* bundles[]= {new PercentageBundleDecorator(),new SubtractionBundleDecorator()};
        return getBundleFromInput(bundles,2);
    }
    if(numberOfOperations>=STAGE_THREE){
        Bundle* bundles[] {
            new PercentageBundleDecorator(),
            new SubtractionBundleDecorator(),
            new PercentageBundleDecorator(new SubtractionBundleDecorator()),
            new SubtractionBundleDecorator(new PercentageBundleDecorator())
        };
        return getBundleFromInput(bundles,4);
    }
    return currentBundle;
}