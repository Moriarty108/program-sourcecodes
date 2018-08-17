#include<iostream>
#define MAX 10
using namespace std;

template <class T> class Stack{
    private:
    T arr[MAX];
    int tos;
    public:
    Stack();
    void push(T element);
    T pop();
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack(){
    tos = -1;
}

template <typename T>
void Stack<T>::push(T element){
    arr[++tos] = element;
}

template <typename T>
T Stack<T>::pop(){
    return arr[tos--];
}

template <typename T>
bool Stack<T>::isEmpty(){
    if(tos == -1)
    return true;
    else return false;
}