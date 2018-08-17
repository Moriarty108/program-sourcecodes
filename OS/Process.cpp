#include<iostream>
#include<string.h>
using namespace std;

class Process{
    private:
    int arrivalTime , burstTime , exitTime;
    int turnAround , responseTime , waitTime;
    string name;
    static char counter;
    public:
    Process(){
        string processName = "Process ";
        processName.push_back(++counter);
        setName(processName);
        turnAround = 0;
        responseTime = 0;
        waitTime = 0;
    }
    void setName(string name){
        (*this).name = name;
    }
    string getName(){
        return name;
    }
    void setArrivalTime(int time){
        arrivalTime = time;
    }
    void setBurstTime(int time){
        burstTime = time;
    }
     void setTurnAroundTime(int time){
        turnAround = time;
    }
     void setResponseTime(int time){
        responseTime = time;
    }
     void setWaitTime(int time){
        waitTime = time;
    }
     void setExitTime(int time){
        exitTime = time;
    }

    int getArrivalTime(){
        return arrivalTime;
    }
    int getBurstTime(){
        return burstTime;
    }
    int getExitTime(){
        return exitTime;
    }
    int getTurnAroundTime(){
        return turnAround;
    }
    int getResponseTime(){
        return responseTime;
    }
    int getWaitTime(){
        return waitTime;
    }
    bool equals(Process& other){
        if((*this).getName().compare(other.getName()) == 0)
        return true;
        else return false;
    }
};
char Process::counter = '0';