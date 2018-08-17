#include<iostream>
using namespace std;

double power(float base , int exponent);

int main(){
    float base;
    int expt;
    cout<<"\n Enter Base : ";
    cin>>base;
    cout<<"\n Enter Exponent :";
    cin>>expt;
    cout<<"\n Result : "<<power(base , expt);
    return 0;
}

double power(float base , int exponent){
    if(exponent == 0)
    return 1;
    if(exponent < 0)
    return power((float)1/base , -exponent);
    else 
    return base * power(base , exponent - 1);
}