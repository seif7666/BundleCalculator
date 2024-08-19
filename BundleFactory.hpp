#include "Bundle.hpp"

#define NUM_OPERATION_FOR_FIRST_BUNDLE 3
#define NUM_OPERATION_FOR_SECOND_STAGE 6
#define STAGE_THREE 8



class BundleFactory{
    public:
        static Bundle* getBundle(int numberOfOperations,Bundle* currentBundle); 
};