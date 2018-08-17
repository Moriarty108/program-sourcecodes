#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "Process.cpp"
using namespace std;

//for setting time when the processes exit the memory
Process  getMinBurst(int  , int  , Process [] , int , Process [] , int &);
//for getting the minimum burst time in the time frame(start_time , end_time)
bool isProcessinCPU(int , int , Process[] , int);
//checking for processes in memory in a specific time frame(start_time , end_time)
void setExitTimes(Process [], int , Process[] );
void display(Process[] , int);
int scan(Process[] , int , Process);
void setTurnaround(Process [], int );
void setWaitT(Process process[], int numOfProc);
void setResponseT(Process process[], int numOfProc);

int main(){
    int numOfProc;
    cout<<"\n Enter Number of Processes : ";
    cin>>numOfProc;
    if(numOfProc <= 0){
        cout<<"\n [Error] '"<<numOfProc<<"' is not valid!\n Exiting!!!";
        exit(-1);
    }
    Process process[numOfProc];
    Process execOrder[numOfProc];//for keeping track of execution of processes

    cout<<"\n => Enter Arrival Times.. ";
    
    for(int i = 0; i < numOfProc; i++)
    {
        cout<<"\n Enter Arrival Time for Process "<<i+1<<" : ";
        int t;
        cin>>t;
        process[i].setArrivalTime(t);
    }

     cout<<"\n => Enter Burst Times.. ";
    
    for(int i = 0; i < numOfProc; i++)
    {
        cout<<"\n Enter Burst Time for Process "<<i+1<<" : ";
        int t;
        cin>>t;
        process[i].setBurstTime(t);
    }
    setExitTimes( process ,  numOfProc , execOrder);
    setTurnaround(execOrder , numOfProc);
    setWaitT(execOrder , numOfProc);
    setResponseT(execOrder , numOfProc);
    cout<<"\n => Order of Execution of Processes : ";
    for(int i = 0; i < numOfProc; i++){
        if(i == numOfProc - 1)
        cout<<execOrder[i].getName();
        else
        cout<<execOrder[i].getName()<<" , ";
        }
    display(execOrder , numOfProc);
    return 0;
}
//for setting time when the processes exit the memory
void setExitTimes(Process process[], int numOfProc , Process execOrder[]){
    Process min , processLeft[numOfProc - 1];
    int sizeOfPL;
    cout<<"\n => Setting up Exit Times..";
    for(int i = 0; i < numOfProc; i++)
    {
        (min).setBurstTime(0);
        if(i == 0){
        process[0].setExitTime(process[0].getArrivalTime() + process[0].getBurstTime());
        execOrder[0] = process[0];
        }
        if(i == 1){
            if(isProcessinCPU(process[0].getArrivalTime() , process[0].getExitTime() , process , numOfProc)){
                min = getMinBurst(process[0].getArrivalTime() , process[0].getExitTime() , process , numOfProc , processLeft , sizeOfPL);
                (min).setExitTime(process[0].getExitTime() + (min).getBurstTime());
                execOrder[i] = min;
                process[scan(process , numOfProc , execOrder[i])] = execOrder[i];
                //for execution of programs still in the memory but not executed 'cause of greater burst time
                 while(sizeOfPL != 0){
                    min = getMinBurst(process[0].getArrivalTime() , process[0].getExitTime() , processLeft , sizeOfPL , processLeft , sizeOfPL);
                    i++;
                    (min).setExitTime(execOrder[i-1].getExitTime() + (min).getBurstTime());
                    execOrder[i] = min;
                    process[scan(process , numOfProc , execOrder[i])] = execOrder[i];
                }
            }
            else if(!(process[i].equals(min))){
                process[i].setExitTime(process[i].getArrivalTime() + process[i].getBurstTime());
                execOrder[i] = process[i];
        }
        }
        else{
            if(isProcessinCPU(execOrder[i-2].getExitTime() , execOrder[i-1].getExitTime() , process , numOfProc)){
                min = getMinBurst(execOrder[i-2].getExitTime() , execOrder[i-1].getExitTime() , process , numOfProc , processLeft , sizeOfPL);
                (min).setExitTime(execOrder[i-1].getExitTime() + (min).getBurstTime());
                execOrder[i] = min;
                process[scan(process , numOfProc , execOrder[i])] = execOrder[i];
                //for execution of programs still in the memory but not executed 'cause of greater burst time
                while(sizeOfPL != 0){
                    min = getMinBurst(execOrder[i-2].getExitTime() , execOrder[i-1].getExitTime() , processLeft , sizeOfPL , processLeft , sizeOfPL);
                    i++;
                    (min).setExitTime(execOrder[i-1].getExitTime() + (min).getBurstTime());
                    execOrder[i] = min;
                    process[scan(process , numOfProc , execOrder[i])] = execOrder[i];
                }
                
            }
                else if(!(process[i].equals(min))) {
                process[i].setExitTime(process[i].getArrivalTime() + process[i].getBurstTime());
                execOrder[i] = process[i];
                }
    }
    }
    cout<<"\t Done!";
}
//for getting the minimum burst time in the time frame(start_time , end_time)
Process  getMinBurst(int start_time , int end_time , Process process[] , int numOfProc , Process processLeft[] , int & sizeOfPL){
    Process  min;
    sizeOfPL = 0;
    (min).setBurstTime(INT32_MAX);
    for(int i = 0; i < numOfProc; i++){
            if(process[i].getArrivalTime() > start_time && process[i].getArrivalTime() <= end_time){
                if(process[i].getBurstTime() < (min).getBurstTime())
                min = process[i];
        }
    }
    for(int i = 0; i < numOfProc; i++){
            if(process[i].getArrivalTime() > start_time && process[i].getArrivalTime() <= end_time){
                if(!(process[i].equals(min)))
                processLeft[sizeOfPL++] = process[i];
        }
    }
    return min;
}
//checking for processes in memory in a specific time frame
bool isProcessinCPU(int start_time , int end_time , Process process[] , int numOfProc){
    bool flag = false;
    for(int i = 0; i < numOfProc; i++)
    {
        if(process[i].getArrivalTime() > start_time && process[i].getArrivalTime() <= end_time){
            flag = true;
            break;
        }
    }
    return flag;
}
void display(Process process[] , int numOfProc){
    cout<<"\n\t\t******************************************************************";
    cout<<"\n\t\t Process                TAT               RT               WT";
    cout<<"\n\t\t******************************************************************";
    for(int i = 0; i < numOfProc; i++)
    {
        cout<<"\n\t\t "<<process[i].getName()<<"                "<<process[i].getTurnAroundTime();
        if(process[i].getTurnAroundTime() > 9){
            cout<<"              "<<process[i].getResponseTime();
            if(process[i].getResponseTime() > 9)
            cout<<"               "<<process[i].getWaitTime();
            else
            cout<<"                "<<process[i].getWaitTime();
        }
        else{
            cout<<"               "<<process[i].getResponseTime();
            if(process[i].getResponseTime() > 9)
            cout<<"               "<<process[i].getWaitTime();
            else
            cout<<"                "<<process[i].getWaitTime();
        }
    }
    cout<<"\n\t\t******************************************************************";
}
int scan(Process process[], int numOfProc , Process process2){
    int pos = -1;
    for(int i = 0; i < numOfProc; i++)
    {
        if(process[i].equals(process2)){
        pos = i;
        break;
        }
    }
    return pos;
}
void setTurnaround(Process process[], int numOfProc){
    cout<<"\n => Setting Arrival Times..";
    for(int i = 0; i < numOfProc; i++){
        process[i].setTurnAroundTime(process[i].getExitTime() - process[i].getArrivalTime());
    }
    cout<<"\t Done!";
}
void setWaitT(Process process[], int numOfProc ){
    cout<<"\n => Setting Wait Times..";
    Process * p;
    for(int i = 0; i < numOfProc; i++)
    {
        if(i == 0){
        process[i].setWaitTime(0);
        }
        else{
        process[i].setWaitTime(process[i-1].getExitTime() - process[i].getArrivalTime());
        }
    }
    cout<<"\t Done!";
}
void setResponseT(Process process[], int numOfProc){
    cout<<"\n => Setting Response Times..";
    
    for(int i = 0; i < numOfProc; i++)
    {
        if(i == 0)
        process[0].setResponseTime(0);
        else
        process[i].setResponseTime(process[i-1].getExitTime() - process[i].getArrivalTime());
    }
    cout<<"\t Done!";
}