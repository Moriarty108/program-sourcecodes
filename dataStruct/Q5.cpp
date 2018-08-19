#include<iostream>
#include "Stack.cpp"
using namespace std;

int main(){
    Stack<int> num_stack;
    int ch;
    
    do
    {
        cout<<"\n ****Stack Implemetation**** ";
        cout<<"\n 1.Push ";
        cout<<"\n 2.Pop ";
        cout<<"\n 3.Clear ";
        cout<<"\n 4.Exit ";
        cout<<"\n Select Option[1-4] : ";
        cin>>ch;
        if(ch == 1){
            cout<<"\n Enter an Integer : ";
            int n;
            cin>>n;
            num_stack.push(n);
            cout<<"\n => '"<<n<<"' pushed...";
        }
        else if(ch == 2){
            if(!(num_stack.isEmpty()))
            cout<<"\n => '"<<num_stack.pop()<<"' popped...";
            else
        cout<<"\n [Error] Nothing to pop";
        }
        else if(ch == 3){
            num_stack.clear();
            cout<<"\n => Stack Cleared";
        }
       
    } while (ch != 4);
    return 0;
}
