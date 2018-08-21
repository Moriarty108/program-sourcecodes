#include<iostream>
#include<cstdlib>
using namespace std;

void setDiagonal(int arr[], int pos, int element);
int getDiagonal(int arr[] , int pos_row , int pos_col);
void displayDiagonal(int arr[] , int size);
void setLower(int arr[] , int pos , int element);
int getLower(int arr[] , int pos_row , int pos_col);
void displayLower(int arr[] , int size);
void setUpper(int arr[] , int pos , int element);
int getUpper(int arr[] , int n , int pos_row , int pos_col);
void displayUpper(int arr[] , int size);
void setTriDiag(int arr[] , int pos , int element);
int getTriDiag(int arr[] , int n , int pos_row , int pos_col);
void displayTriDiag(int arr[] , int size);

int main(){
    cout<<"\n *****Matrix Imp*****";
    cout<<"\n 1.Diagonal Matrix";
    cout<<"\n 2.Lower Triangular Matrix";
    cout<<"\n 3.Upper Triangular Matrix";
    cout<<"\n 4.Tri-Diagonal Matrix";
    cout<<"\n Select [1-4]: ";
    int ch , size;
    cin>>ch;
    if(ch >= 1 && ch <= 4){
        cout<<"\n Enter Size of the Matrix : ";
        cin>>size;
        }
        else{
        cout<<"\n [error] Option not Valid! \n Exitting!!!\n";
        exit(-1);
    }
    if(ch == 1){
        int arr[size];
        cout<<"\n => Enter Diagonal Elements..";
        
        for(int i = 0; i < size; i++)
        {
            cout<<"\n Enter Element (row: "<<i<<", col: "<<i<<") :";
            int num;
            cin>>num;
            setDiagonal(arr , i , num);
        }
        cout<<"\nMatrix :\n";
        displayDiagonal(arr , size);
        
    }
    else if(ch == 2){
        int k = (size * (size + 1) )/ 2;
        int arr[k];

        cout<<"\n => Enter Elements..";
        
        for(int i = 0; i < k; i++)
        {
            cout<<"\n Enter Element :";
            int num;
            cin>>num;
            setLower(arr , i , num);
        }
        displayLower(arr , size);
    }

    else if(ch == 3){
        int k = (size * (size + 1) )/ 2;
        int arr[k];

        cout<<"\n => Enter Elements..";
        
        for(int i = 0; i < k; i++)
        {
            cout<<"\n Enter Element :";
            int num;
            cin>>num;
            setUpper(arr , i , num);
        }
        displayUpper(arr , size);
    }

    else if(ch == 4){
        int k = (3 * size) - 2; 
        int arr[k];

        cout<<"\n => Enter Elements..";
        
        for(int i = 0; i < k; i++)
        {
            cout<<"\n Enter Element :";
            int num;
            cin>>num;
            setTriDiag(arr , i , num);
        }
        displayTriDiag(arr , size);
    }
    
    return 0;
}

void setDiagonal(int arr[], int pos, int element){
    arr[pos] = element;
}

int getDiagonal(int arr[] , int pos_row , int pos_col){
    if(pos_row == pos_col)
    return arr[pos_row];
    else
    return 0;
}

void displayDiagonal(int arr[] , int size){
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<getDiagonal(arr , i , j)<<" ";
        }
        cout<<"\n";
    }
}

void setLower(int arr[] , int pos , int element){
    arr[pos] = element;
}

int getLower(int arr[] , int pos_row , int pos_col){
    if(pos_row >= pos_col){
        int x = pos_row , y = pos_col;
        int index = (x * (x + 1))/2 + y;
        return arr[index];
    }
    else return 0;
}

void displayLower(int arr[] , int size){
    for(int  i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<getLower(arr , i , j)<<" ";
        }
        cout<<"\n";
    }
}

void setUpper(int arr[] , int pos , int element){
    arr[pos] = element;
}

int getUpper(int arr[] , int n , int pos_row , int pos_col){
    if(pos_row <= pos_col){
        int x = pos_row , y = pos_col;
        int index = (x * (2 * n - x - 1))/2 + y;
        return arr[index];
    }
    else return 0;
}

void displayUpper(int arr[] , int size){
    for(int  i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<getUpper(arr , size , i , j)<<" ";
        }
        cout<<"\n";
    }
}

void setTriDiag(int arr[] , int pos , int element){
    arr[pos] = element;
}

int getTriDiag(int arr[] , int n , int pos_row , int pos_col){
    static int x = 2;
    static int y = 2;
    if(pos_row == pos_col){
        return arr[n + pos_row - 2];
    }
    else if((pos_row == x) && (pos_col == (x - 1))){
        x++;
        return arr[pos_row - 2];
    }
    else if((pos_row == (y - 1)) && (pos_col == y)){
        y++;
        return arr[2 * n + pos_row - 2];
    }
    else return 0;
}

void displayTriDiag(int arr[] , int size){
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            cout<<getTriDiag(arr , size , i , j)<<" ";
        }
        cout<<"\n";
    }
}