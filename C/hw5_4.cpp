#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){

    unsigned int n;
    cin >>n;
    if(n<1||n>1000)
        cout<<"error"<<endl;
    int t=0;
    while(t++<100){
        usleep(1000*n);
        system("clear");
        for(int i=t;i<t+10;i++)
            cout<<i%10;
        cout<<endl;
    }
    return 0;
}
