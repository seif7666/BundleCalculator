#ifndef BUNDLE_H
#define BUNDLE_H
#include <iostream>
class Bundle{
    protected:
        std::string bundleName;
        Bundle(std::string name){
            this->bundleName= name;
        }
    public:
        Bundle():Bundle("Plain"){ }
        virtual double compute(double price);
        virtual std::string getBundleName();
};
class BundleDecorator: public Bundle{
    protected:
        Bundle* bundle;
    public:
        BundleDecorator(Bundle* bundle, std::string name):Bundle(name){
            this->bundle= bundle;
        }
        BundleDecorator(std::string name): BundleDecorator(new Bundle(), name){}
        virtual double compute(double price)=0;
        std::string getBundleName();
};
class PercentageBundleDecorator: public BundleDecorator{
    public:
        PercentageBundleDecorator(Bundle* bundle):BundleDecorator(bundle,"15% Bundle"){}
        PercentageBundleDecorator():BundleDecorator("15% Bundle"){}
        double compute(double price);
};
class SubtractionBundleDecorator: public BundleDecorator{
    public:
        SubtractionBundleDecorator(Bundle* bundle):BundleDecorator(bundle,"-100 Bundle"){}
        SubtractionBundleDecorator():BundleDecorator("-100 Bundle"){}
        double compute(double price);
};
#endif