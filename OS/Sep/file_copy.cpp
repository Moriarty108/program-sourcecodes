#include<iostream>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //NOTE Source File
    char sfile[30];
    //NOTE destination file
    char tfile[30];
    char buf[1000];

    int sd,td,n;

    cout<<"Enter the source filename :";
    cin>>sfile;
    cout<<"Enter the target filename :";
    cin>>tfile;

    if((sd = open(sfile,O_RDONLY)) < 0)//NOTE O_RDONLY is the flag
    {
        cout<<"Error Opening File";
        exit(1);
    }

    if((td = open(tfile,O_CREAT|O_WRONLY, 0666)) < 0)//NOTE 0666 is the mode
    {
        cout<<"Error Creating file";
        close(sd);
        exit(2);
    }
    while((n = read(sd,buf,sizeof(buf))) > 0)
    write(td,buf,n);
    close(sd);
    close(td);
    cout<<"\nFile Copied\n";
    return 0;
}
