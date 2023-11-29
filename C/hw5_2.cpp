#include<iostream>

using namespace std;

int main(){
    int n;
    float x[10];
    float y[10];
    float z[10];
    cin >>n;
    if(n==3){
        for(int i=0;i<n+1;i++)
            cin >>x[i];
        for(int i=0;i<n+1;i++)
            cin >>y[i];
        for(int i=0;i<n+1;i++)
            cin >>z[i];
        
        float factor =x[0]; 
        //step1
        for(int i=0;i<n+1;i++)
            x[i]/factor;
        factor = y[0];
        //step2
        for(int i=0;i<n+1;i++)
            y[i] -=factor*x[i];
        factor = z[0];
        for(int i=0;i<n+1;i++)
            z[i] -=factor*x[i];
        //step3
        factor = z[1]/y[1];
        for(int i=1;i<n+1;i++)
            z[i] -=factor*y[i];
        //step4
        factor = y[2]/z[2];
        
        for(int i=2;i<n+1;i++)
            y[i] -=factor*z[i];
        for(int i=2;i<n+1;i++)
            x[i] -=factor*z[i];
        factor = x[1]/y[1];
        for(int i=1;i<n+1;i++)
            x[i] -=factor*y[i];

        
    }
    return 0;

}