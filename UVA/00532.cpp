#include <iostream>
#include <string>
#include <cmath>
#include<queue>
using namespace std;
char s[32][32][32];
int ans[32][32][32];
const int direction[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,-1},{0,0,1}};
int l,r,c;
struct point_type{
    int x;
    int y;
    int z;
};
int BFS(int i, int j ,int k){

    ans[i][j][k]=0;
    queue<point_type> q;
    q.push(point_type {i,j,k} );
     s[i][j][k]='#';
     
     point_type cur, nex;
     while(!q.empty()){

        cur=q.front();
        q.pop();

        for(int i=0;i<6;i++){
            nex.x=cur.x+direction[i][0];
            nex.y=cur.y+direction[i][1];
            nex.z=cur.z+direction[i][2];
            if(nex.x<0||nex.x>=l|| nex.y<0||nex.y>=r||nex.z<0||nex.z>=c)continue;

            if(s[nex.x][nex.y][nex.z]!='#'){   
                ans[nex.x][nex.y][nex.z]=ans[cur.x][cur.y][cur.z]+1;
                if(s[nex.x][nex.y][nex.z]=='E')
                return ans[nex.x][nex.y][nex.z];
                s[nex.x][nex.y][nex.z]='#';
                q.push(nex);
            }
        }   
}
   return -1;
}              
int main(){

    while(cin >>l>>r>>c&&l>0){
    
    int start_i,start_j,start_k;
    
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            cin >>s[i][j];
            for(int k=0;k<c;k++)
                if(s[i][j][k]=='S'){
                    start_i=i;
                    start_j=j;
                    start_k=k;
                }
        }
    }          
    
    int minute=BFS(start_i,start_j,start_k);
    if(minute!=-1)
    cout<<"Escaped in "<<minute<<" minute(s)."<<endl;
    else
    cout <<"Trapped!"<<endl;
    
    
}
    
    
    
    
    
    
    
    return 0;
}