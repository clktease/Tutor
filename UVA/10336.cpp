#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;
char c[1001][1001]={0};
void DFS(int i,int j,char p){

   if(c[i+1][j]==p){
        c[i+1][j]='.';
        DFS(i+1,j,p);
   }
   if(c[i][j+1]==p){
        c[i][j+1]='.';
        DFS(i,j+1,p);
    }
   if(c[i-1][j]==p){
        c[i-1][j]='.';
        DFS(i-1,j,p);
   }
   if(c[i][j-1]==p){
        c[i][j-1]='.';
        DFS(i,j-1,p);
    }
   
     
}
int main(){
    
    int n,count=1;;
    cin >>n;
    while(n--){

    int a, b,f[26]={0};
    cin>>a>>b;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
        cin >>c[i][j];

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(c[i][j]>='a'&&c[i][j]<='z'){
                f[c[i][j]-'a']++;

                DFS(i,j,c[i][j]);
                c[i][j]='.';
            }
        }
    }

    int max=0;
    for(int i=0;i<26;i++)    
        if(f[i]>max)
             max=f[i];
    cout <<"World #"<<count<<endl;  
    for(int i=max;i>0;i--){
        for(int j=0;j<26;j++){        
            if(f[j]==i)
                cout <<char(j+'a')<<": "<<i<<endl;
            }
        }
    
            
            count ++;
            }
    
    

    
    return 0;
}