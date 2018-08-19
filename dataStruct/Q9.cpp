#include<iostream>
#include<string.h>
#include<math.h>
#include "Stack.cpp"
using namespace std;

bool isNumber(char c);
bool isOperator(char c , char opLib[]);
float performOperation(int operand1 , int operand2 , char operation);
float evaluate(string expression);

int main(){
    string expression;
    cout<<"\n Enter an Expression : ";
    cin>>expression;
    cout<<"\n => Result : "<<evaluate(expression)<<endl;
}

bool isNumber(char c){
    if(c >= '0' && c <= '9')
    return true;
    else return false;
}

bool isOperator(char c , char opLib[]){
    bool found = false;
    for(int i = 0; i < strlen(opLib); i++){
        if(c == opLib[i]){
            found = true;
            break;
        }
    }
    return found;
}

float performOperation(int operand1 , int operand2 , char operation){
    
    switch (operation)
    {
        case '+':
            return operand1 + operand2;
            break;
        case '-':
            return operand1 - operand2;
            break;
        case '*':
            return operand1 * operand2;
            break;
        case '/':
            return (float)operand1 / operand2;
            break;    
        case '^':
            return pow(operand1 , operand2);
        default: //Enter default case here
            break;
    }
}

float evaluate(string expression){
    Stack<float> numberStack;
    //operator Library for storing operators
    char opLib[] = {'+' , '-' , '*' , '/' , '^'};
       for(int i = 0; i < expression.length(); i++){
        if(isNumber(expression[i]))
        numberStack.push(expression[i] - 48);
        else if(isOperator(expression[i] , opLib)){
            if(numberStack.getTOS() >= 1){
                float num2 = numberStack.pop();
                float num1 = numberStack.pop();
                numberStack.push(performOperation(num1 , num2 , expression[i]));
            }
            //checking if values provided are enough for operation
            else if(numberStack.getTOS() < 1){
                cout<<"\n [Error] Invalid Expression!\n";
                exit(-1);
            }
        }
        //if user provided any operator which is not supported
        else{
            cout<<"\n => [Error] '"<<expression[i]<<"' is an invalid operator\n";
            exit(-1);
        }
        /* Checking if there are more than one result left in stack,
           if that's the case then the user has not provided the complete expression! 
        */
        if(i == (expression.length() - 1)){
            if(numberStack.getTOS() >= 1){
                cout<<"\n [Error] Complete Expression Not Provided!\n";
                exit(-1);
            }
        }
    }   
    return numberStack.pop();
}