#include<iostream>
using namespace std;

int revOf(int num);

int main(){
    cout<<"\n Enter a Number : ";
    int num;
    cin>>num;
    cout<<" Reverse of "<<num<<" is : "<<revOf(num);
    return 0;
}

int revOf(int num){
    static int rev = 0;
    if(num == 0)
    return rev;
    else{
        int rem = num % 10;
        rev = rev * 10 + rem;
        revOf(num /= 10);
    }
}