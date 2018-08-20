#include<iostream>
using namespace std;

void display(int [], int[], int [], float[], int);
int main(){
    cout<<"Enter Number of Processes :";
    int n;cin>>n;
    int burstTime[n] , exitTime[n], turnAround[n], waitTime[n], responseTime[n];
    
    for(int i = 0; i < n; i++)
    {
        burstTime[i] = exitTime[i] = turnAround[i] = waitTime[i] = responseTime[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        cout<<"Enter Burst time for process "<<i+1<<":";
        cin>>burstTime[i];
        if(i == 0){
            exitTime[0] = burstTime[0];
            responseTime[0] = 0;
            waitTime[0] = 0;
            turnAround[i] = exitTime[i];
        }
        else{
            exitTime[i] = burstTime[i] + exitTime[i-1];
            responseTime[i] = exitTime[i-1];
            waitTime[i] = exitTime[i-1];
            turnAround[i] = exitTime[i];
        }
    }
    float avg[3] = {0};
    for(int i = 0; i < 3; i++)
    {
        if(i == 0){
            for(int j = 0; j < n; j++)
            {
                avg[i] += turnAround[j];
            }
            avg[i] = (float)avg[i]/n;
        }
        else if(i == 1){
            for(int j = 0; j < n; j++)
            {
                avg[i] += responseTime[j];
            }
            avg[i] = (float)avg[i]/n;
        }
        else if(i == 2){
            for(int j = 0; j < n; j++)
            {
                avg[i] += waitTime[j];
            }
            avg[i] = (float)avg[i]/n;
        }
    }
    display(turnAround, responseTime, waitTime, avg, n);
    return 0;
}

void display(int turnAround[], int responseTime[], int waitTime[], float avg[], int size){
    cout<<"\t     ------------------------------"<<endl;
    cout<<"\t      TAT         RT            WT"<<endl;
    cout<<"\t     ------------------------------"<<endl;
    for(int i = 0; i < size; i++)
    {
        cout<<"\t       "<<turnAround[i];
        if(turnAround[i]<10){
        cout<<"           "<<responseTime[i]<<"            "<<waitTime[i]<<endl;
        }
        else {
        cout<<"          "<<responseTime[i];
        if(responseTime[i]>10)
          cout<<"           "<<waitTime[i]<<endl;
          else
          cout<<"            "<<waitTime[i]<<endl;
        }
    }
    cout<<"\t     ------------------------------"<<endl;
    cout<<"\tAVG   "<<avg[0]<<"        "<<avg[1]<<"          "<<avg[2]<<endl;;
    cout<<"\t     ------------------------------"<<endl;
}