#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>

class Logger{
    private:
        static Logger* singletonInstance;
        std::string fileName;
        Logger();
        std::string getCurrentTimeStamp();
        void writeToFile(std::string log);
        void prepareLog(std::string log);
    public:
        void info(std::string data);
        void warn(std::string data);
        void debug(std::string data);
        static Logger* getLogger();
};

#endif