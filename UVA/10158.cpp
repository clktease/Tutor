#include<iostream>
#include<set>
using namespace std;

int f[10005]={0};
int p[10005]={0};


int  find(int x){
             
    return x==f[x]?x:f[x] = find(f[x]);
}
void merge(int x,int y){
    //cout<<"merge"<<x<<y<<endl;
    x = find(x);
    y = find(y);
    int ex = p[x],ey=p[y];
    p[ex] = x
    if(ex!=-1){
        p[ey] = x;
        p[x] = ey;
    }
    f[y] = x;
    if(ex!=-1&&ey!=-1 && find(ex)!=find(ey)){
        merge(ey,ex);
    }
    

    
    return;
}
void split(int x,int y){
    x = find(x);
    y = find(y);
    int c = p[x];
    int d = p[y];
    //cout<<x<<y<<" "<<c<<d<<endl;
    if(c!=-1)
        merge(c,y);
    if(d!=-1)
        merge(d,x);
    p[x] = y;
    p[y] = x;

    return;
}
int main(){


    int n;
    cin >>n;
    for(int i=0;i<n;i++)
        f[i]=i,p[i]=-1;
    int t,x,y;
    while(cin >>t&&t){
        cin >>x>>y;
        if(t==1){
            if( find(x)!=find(y) ){
                if(p[find(x)]==find(y)||p[find(y)] == find(x))
                    cout<<"-1"<<endl;
                else{
                    merge(x,y);
                }
            }

        }
        else if(t==2){
            if(x==y||find(x)==find(y))
                cout<<"-1"<<endl;
            else
                split(x,y);
        }
        else if(t==3){
            if(find(x)==find(y))
                cout<<"1"<<endl;
            else    
                cout<<"0"<<endl;
        }
        else{
            if(p[find(x)]==find(y)||p[find(y)] == find(x))
                cout<<"1"<<endl;
            else    
                cout<<"0"<<endl;
        }
        /*
        for(int i=0;i<10;i++)
            cout<<f[i]<<" ";
        cout <<endl;
        for(int i=0;i<10;i++)
            cout<<p[i]<<" ";
        cout <<endl;*/
    }


    return 0;
}