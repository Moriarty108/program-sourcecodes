#include<iostream>
#include "Stack.cpp"
using namespace std;

int main(){
    Stack<int> num_stack;
    int num;
    cout<<"\n Enter Number 1 : ";
    cin>>num;
    num_stack.push(num);
    cout<<"\n Enter Number 2 : ";
    cin>>num;
    num_stack.push(num);
    cout<<"\n Result : "<<num_stack.pop() + num_stack.pop();
    return 0;
}