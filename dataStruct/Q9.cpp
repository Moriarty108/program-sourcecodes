//Remove me when this program is Done!
#include<iostream>
#include<string>
#include<ctype.h>
#include "Stack.cpp"
using namespace std;

int cal(int num1 , char op , int num2);

int main(){
    char expn[20] = {""};
    Stack<int> numberStack;
    Stack<char> operandStack;
    cout<<"\n Enter an Expression : ";
    gets(expn);
    
    for(int i = 0; expn[i] != '\0'; i++)
    {
        if(expn[i] >= '0' && expn[i] <= '9')
        numberStack.push(expn[i] - 48);
        else
        operandStack.push(expn[i]);
    }
    int a = numberStack.pop();
    int b = numberStack.pop();
    cout<<"\n => Result :"<<cal(b , operandStack.pop() , a);
    return 0;
}
int cal(int num1 , char op , int num2){
    if(op == '+')
    return num1 + num2;
}