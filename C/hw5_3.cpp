#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ifstream file;
    file.open("input.txt");
    int number[40]={0}; 
    int result[40]={0};
    int n;
    int a=0,b=0,c=0;
    while(file>>n && n!=-1){
        if(n>9 && n<19)
            n++;
        else if(n>18 && n<28)
            n+=2;
        else if(n>27 &&n <35)
            n+=3;
        else if(n<1||n>34)    
            cout<<"error"<<endl;
        number[n]++;
        result[n]++;
    }
    /*
    1 2 3 1 2 3 1 2 3   11 12 13 14 15 15 15 17 17
    result               1 1   1 1 1   3 ->0
    1 2 3  ->   1 2 3
    3 3 3  a=1  2 2 2    0 0 0  0 0 0 

    K=1         1 1 1
    K=2         0 0 0
    K=5
    */
    for(int k=0;k<3;k++){
        for(int i=1;i<30;i++)
            if(result[i]&&result[i+1]&&result[i+2])
                a++,result[i]--,result[i+1]--,result[i+2]--;
    }
    /*
    for(int i=0;i<30;i++)
        if(result[i])
            cout<<i<<" "<<result[i]<<endl;
            */
    
    for(int i=0;i<38;i++)
        if(result[i]>2&&a+b<5)
            b++,result[i]-=3;
    for(int i=0;i<38;i++)
        if(result[i]>1)
            c++,result[i]-=2;

    cout<<a<<" "<<b<<" "<<c<<endl;

    if(a+b<5||c==0){
        for(int i=0;i<30;i++){
            if(c==0 && result[i]&&result[i+3]&&number[i]&&number[i+1]&&number[i+2]){
                c++;
                result[i]--,result[i+3]--;
            }               
        }
        for(int i=0;i<30;i++){
            if(c>1&& (result[i]&&number[i-3]>2&&number[i-2]&&number[i-1])){
                c--;
                a++;
                result[i]--;
            } 
        }
        
    }
    if(a+b>=5 && c)
        cout<<a<<" "<<b<<" "<<c<<" Win"<<endl;
    else{
        cout<<a<<" "<<b<<" "<<c<<" lose"<<endl;
    }
    

    

    return 0;
}