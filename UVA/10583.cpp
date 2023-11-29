#include<iostream>

using namespace std;

int f[50005];
int rank1[50005];
int  find(int x){
    
    return f[x]==x ? x:f[x] = find(f[x]);
    
}
bool merge(int x,int y){
 
    int x1 = find(x);
    int y1 = find(y);
    if(x1==y1)
        return false;
    else{
        if(rank1[x1]>rank1[y1])
            f[y1] = x1;
        else
            f[x1] = y1;
        if(x1==y1)
            1tree rank1[x1] +=1;
            2 rank1[x1] += rank1[y1];
    }
    return true;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,t=1;
    int x,y;
    while(cin >>a>>b &&a+b){
        int count =a;
        for(int i=0;i<=a;i++)
            f[i] = i,rank1[i] = 1;
        
        for(int i=0;i<b;i++){
            cin >>x>>y;
            if(merge(x,y)){              
                count--;
            }
        }
        cout<<"Case "<<t++<<": "<<count<<endl;
    }

    return 0;
}