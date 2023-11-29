#include<iostream>

using namespace std;

int main(){

    int  type;
    cin >>type;
    int m1[105][105]={0};
    int m2[105][105]={0};
    int result[105][105]={0};
    int x1,x2;
    int y1,y2;

    cin >>x1>>x2;
    for(int i=0;i<x1;i++){
        for(int j=0;j<x2;j++){
            cin >>m1[i][j];
        }
    }
    cin >>y1>>y2;
    for(int i=0;i<y1;i++){
        for(int j=0;j<y2;j++){
            cin >>m2[i][j];
        }
    }
    if(type ==1){
        if(x1!=y1||x2!=y2)
            cout <<"error"<<endl;
        else{
            for(int i=0;i<x1;i++){
                for(int j=0;j<x2;j++){
                    result[i][j] = m1[i][j]+m2[i][j];
                }
            }
        }
    }
    else if(type ==2){
        if(x1!=y1||x2!=y2)
            cout <<"error"<<endl;
        else{
            for(int i=0;i<x1;i++){
                for(int j=0;j<x2;j++){
                    result[i][j] = m1[i][j]-m2[i][j];
                }
            }
        }
    }
    else if(type ==3){
        if(x2!=y1)
            cout <<"error"<<endl;
        else{
            for(int i=0;i<x1;i++){
                for(int j=0;j<y2;j++){
                    int ans = 0;
                    for(int k=0;k<x2;k++)
                        ans+=m1[i][k]*m2[k][j];
                    result[i][j] = ans;
                }
            }
        }
    }
    else{
        cout<<"error"<<endl;
    }
    
    for(int i=0;i<x1;i++){
        for(int j=0;j<y2;j++)
            cout<<result[i][j]<<" ";
    cout<<endl;
    }
    
    return 0;
}