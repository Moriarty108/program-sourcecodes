#include<iostream>
using namespace std;

int revOf(int num);

int main(){
    cout<<"Enter a Number :";
    int num;
    cin>>num;
    cout<<"Reverse of "<<num<<" is : "<<revOf(num);
    return 0;
}