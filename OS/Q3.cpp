#include<iostream>
#include<stdlib.h>
#include "Process.cpp"
using namespace std;

int main(){
    int numOfProc , timeSlice;
    cout<<"\n Enter Number of Processes : ";
    cin>>numOfProc;
    cout<<"\n Enter Time Slice : ";
    cin>>timeSlice;
    Process process[numOfProc] , execOrder[2*numOfProc];
     if(numOfProc <= 0){
        cout<<"\n [Error] '"<<numOfProc<<"' is not valid!\n Exiting!!!";
        exit(-1);
    }
    cout<<"\n => Enter Arrival Times..";
    for(int i = 0; i < numOfProc; i++)
    {
        cout<<"\n Enter Arrival Time for Process "<<i+1<<" : ";
        int t;
        cin>>t;
        process[i].setArrivalTime(t);
    }
    cout<<"\n => Enter Burst Times..";
    for(int i = 0; i < numOfProc; i++)
    {
        cout<<"\n Enter Burst Time for Process "<<i+1<<" : ";
        int t;
        cin>>t;
        process[i].setBurstTime(t);
    }
    
}
