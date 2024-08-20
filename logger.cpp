#include "logger.hpp"
#include <iostream>
#include <fstream>
#include <chrono> 
using namespace std;

Logger* Logger::singletonInstance= nullptr;

Logger::Logger(){
    this->fileName= "data.log";
    ofstream ofstream(this->fileName);
    ofstream.close();
}
string Logger::getCurrentTimeStamp(){
    auto millis = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count() % 1000;
    auto t = std::time(0);
    auto now = std::localtime(&t);
    char buffer[sizeof "9999-12-31 29:59:59.9999"];
    sprintf(
        buffer,
        "%04d-%02d-%02d %02d:%02d:%02d.%lld",
        now->tm_year + 1900,
        now->tm_mon + 1,
        now->tm_mday,
        now->tm_hour,
        now->tm_min,
        now->tm_sec,
        millis);

    return buffer;
}
void Logger::writeToFile(string log){
    ofstream ofstream(this->fileName,ios::app);
    ofstream<<log<<endl;
    ofstream.close();
}
void Logger::prepareLog(string log){
    string timestamp= this->getCurrentTimeStamp();
    string completeLog= "["+timestamp + "]"+log;
    this->writeToFile(completeLog);
}
void Logger::info(string data){
    this->prepareLog("[INFO]: ["+data+"]");
}
void Logger::warn(std::string data){
    this->prepareLog("[WARN]: ["+data+"]");
}
void Logger::debug(std::string data){
    this->prepareLog("[DEBUG]: ["+data+"]");
}
Logger* Logger::getLogger(){
    if(singletonInstance== NULL)
        singletonInstance= new Logger();
    return singletonInstance;
 }