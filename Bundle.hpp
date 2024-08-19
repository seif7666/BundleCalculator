#ifndef BUNDLE_H
#define BUNDLE_H
#include <iostream>
class Bundle{
    public:
        std::string bundleName;
    public:
        Bundle(std::string name){
            this->bundleName= name;
        }
        Bundle():Bundle("Plain"){ }
        virtual double compute(double price);
        virtual std::string getBundleName(){return this->bundleName;};
};
class BundleDecorator: public Bundle{
    protected:
        Bundle* bundle;
    public:
        BundleDecorator(Bundle* bundle, std::string name):Bundle(name){
            this->bundle= bundle;
        }
        virtual double compute(double price)=0;
        std::string getBundleName();
};
class PercentageBundleDecorator: public BundleDecorator{
    public:
        PercentageBundleDecorator(Bundle* bundle):BundleDecorator(bundle,"15% Bundle"){}
        double compute(double price);
};
class SubtractionBundleDecorator: public BundleDecorator{
    public:
        SubtractionBundleDecorator(Bundle* bundle):BundleDecorator(bundle,"-100 Bundle"){}
        double compute(double price);
};
#endif