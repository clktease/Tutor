#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int32_t check_valid(int32_t x,int32_t y,int32_t k ,int32_t board[10][9]){
    //check if any chess in illegal position
    if(k==0)
        return 1;
    //general need to in 9 palace grid
    if(k==1){
        if(x<=2 && y>=3&&y<=5)
            return 1;
        else
            return 0;
    }
    else if(k==11){
        if(x>=7 && y>=3&&y<=5)
            return 1;
        else
            return 0;
    }
    //advisor need to in 9 palace grid
    else if(k==2){
        if(x<=2 && y>=3&&y<=5&& (x+y)%2==1)
            return 1;
        else
            return 0;
    }
    else if(k==12){
        if(x>=7 && y>=3&&y<=5&& (x+y)%2==0)
            return 1;
        else
            return 0;
    }
    //elephant can not cross river
    else if(k==3){
        if(x<=4 && x%2==0 && (y-2)%2==0 && (x+y-2)%4==0)
            return 1;
        else 
            return 0;
    }
    else if(k==13){
        if(x>=5&& (x-1)%2==0 && (y-2)%2==0 && (x+y-1-2)%4==0)
            return 1;
        else 
            return 0;
    }
    //soldier
    else if(k==7){
        if(x>=5|| (( (x==3&&board[x+1][y]!=7) || x==4) &&y%2==0) )
            return 1;
        else
            return 0;
    }
    else if(k==17){
        if(x<=4|| (( (x==6&&board[x-1][y]!=17) || x==5) &&y%2==0) )
            return 1;
        else
            return 0;
    }
    //other chess can be in any position
    else
        return 1;

}
int32_t checkmate(int32_t board[10][9]){
    int checknum[18]={0};
    int x,y;
    int ans = 0;
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 9;j++){
            if(board[i][j]<0||(board[i][j]>7&&board[i][j]<11)||board[i][j]>17)
                return -1;
            checknum[board[i][j]]++;
            if(!check_valid(i,j,board[i][j],board)){
                return -1;
            }
            if(board[i][j]==11)
                x = i,y = j;
        }
    }
    for(int i=1;i<18;i++){
        if(i!=7&&i!=17&&checknum[i]>2)
            return -1;
        if((i==1||i==11)&&(checknum[i]!=1))
            return -1;
        if((i==7||i==17)&&checknum[i]>5)
            return -1;
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 9;j++){
            //board[i][j] <4 can not cross over the river

            //horse dirction
            if(board[i][j] == 4){
                int direction[8][2]={
                    -2,-1,-2,1,-1,-2,-1,2
                    ,1,-2,1,2,2,-1,2,1,};
                //Stumbling
                int relate[8][2]={
                    -1,0,-1,0,0,-1,0,1,    
                    0,-1,0,1,1,0,1,0
                };
                for(int k=0;k<8;k++){
                    int a =i+direction[k][0];
                    int b =j+direction[k][1];
                    //check first move legal position and stumbling
                    if(a>=0&&a<10 &&b>=0&&b<9 &&(board[a][b]==0||board[a][b]>=12)&& board[i+relate[k][0]][j+relate[k][1]]==0){
                        for(int q=0;q<8;q++){
                            int c =a+direction[q][0];
                            int d =b+direction[q][1];
                            ///check second move legal position and stumbling
                            if(c==x&&d==y&&board[a+relate[q][0]][b+relate[q][1]]==0){
                                printf("%d) Move Horse from(%d,%d) to (%d,%d)\n",ans+1,i,j,a,b);
                                ans++;
                            }
                        }
                    }
                }
            }
            else if(board[i][j] == 5){
                int valid=1,valid_l=1,valid_r=1,valid_u = 1,valid_d=1;
                int count = 0;
                    for(int k=j+1;k<y;k++){
                        if(board[x][k]!=0)
                            valid_l = 0;
                        }
                    for(int k=y+1;k<j;k++){
                        if(board[x][k]!=0)
                            valid_r = 0;
                        }
                
                if(i>x){
                    
                        for(int k=i-1;k>x;k--){
                            if(board[k][y]!=0)
                                valid_u = 0;
                        }
                    if(j>y){
                        valid = 1;
                        for(int k=i-1;k>x;k--)
                            if(board[k][j]!=0)
                                valid = 0;
                        if(board[x][j]>=1&&board[x][j]<=7)
                            valid = 0;
                        if(valid && valid_r){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                        }
                        valid = 1;
                        for(int k=y+1;k<j;k++)
                            if(board[i][k]!=0)
                                valid = 0;
                        if(board[i][y]>=1&&board[i][y]<=7)
                            valid = 0;
                        if(valid && valid_u){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                        }
                    }
                    else if(j<y){
                        for(int k=i-1;k>x;k--)
                            if(board[k][j]!=0)
                                valid = 0;
                        if(board[x][j]>=1&&board[x][j]<=7)
                            valid = 0;
                        if(valid && valid_l){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                        }
                        valid = 1;
                        for(int k=j+1;k<y;k++)
                            if(board[i][k]!=0)
                                valid = 0;
                        if(board[i][y]>=1&&board[i][y]<=7)
                            valid = 0;
                        if(valid && valid_u){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                        }
                    }
                    else{
                        int count = 0,p=-1;
                        for(int k=i-1;k>x;k--){
                            if(board[k][y]>=1&&board[k][y]<=7)
                                valid = 0;
                            else if(board[k][y]!=0)
                                count++,p=k;
                        }
                        if(valid && count==1){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,p,y);
                            ans++;
                        }
                    }
                }
                else if (i<x){
                    if(j>y){
                        for(int k=i+1;k<x;k++){
                            if(board[k][y]!=0)
                                valid_d = 0;
                        }

                        for(int k=y+1;k<j;k++)
                            if(board[i][k]!=0)
                                valid = 0;
                        if(board[i][y]>=1&&board[i][y]<=7)
                            valid = 0;
                        if(valid && valid_d){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                        }
                        valid = 1;
                        for(int k=i+1;k<x;k++)
                            if(board[k][j]!=0)
                                valid = 0;
                        if(board[x][j]>=1&&board[x][j]<=7)
                            valid = 0;
                        if(valid && valid_r){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                        }
                    }
                    else if(j<y){
                        for(int k=j+1;k<y;k++)
                            if(board[i][k]!=0)
                                valid = 0;
                        if(board[i][y]>=1&&board[i][y]<=7)
                            valid = 0;
                        if(valid && valid_d){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                        }
                        valid = 1;
                        for(int k=i+1;k<x;k++)
                            if(board[k][j]!=0)
                                valid = 0;
                        if(board[x][j]>=1&&board[x][j]<=7)
                            valid = 0;
                        if(valid && valid_l){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                        }
                    }
                    else{
                        int count = 0,p=-1;
                        for(int k=i+1;k<x;k++){
                            if(board[k][y]>=1&&board[k][y]<=7)
                                valid = 0;
                            else if(board[k][y]!=0)
                                count++,p=k;
                        }
                        if(valid && count==1){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,p,y);
                            ans++;
                        }
                    }
                }
                else{
                    if(j>y){
                        int count = 0,p=-1;
                        for(int k=y+1;k<j;k++){
                            if(board[k][y]>=1&&board[x][k]<=7)
                                valid = 0;
                            else if(board[x][k]!=0)
                                count++,p=k;
                        }
                        if(valid && count==1){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,x,p);
                            ans++;
                        }
                    }
                    else{
                        int count = 0,p=-1;
                        for(int k=j+1;k<y;k++){
                            if(board[k][y]>=1&&board[x][k]<=7)
                                valid = 0;
                            else if(board[x][k]!=0)
                                count++,p=k;
                        }
                        if(valid && count==1){
                            printf("Move Chariot from(%d,%d) to (%d,%d)\n",i,j,x,p);
                            ans++;
                        }
                    }
                }
            }
            else if(board[i][j] == 6){
                int valid=1,valid_l=1,valid_r=1,valid_u = 1,valid_d=1;
                int valid_il=1,valid_ir=1,valid_ju = 1,valid_jd=1;
                int count = 0,p=-1;
                    for(int k=j+1;k<=y;k++){
                        if(board[i][k]!=0)
                            count++;
                        }
                    if(count>1||(count==1&&board[i][y]<11)) 
                        valid_ir = 0;
                    count = 0;
                    for(int k=y+1;k<j;k++){
                        if(board[i][k]!=0)
                            count++;
                    }
                    if(count>1||(count==1&&board[i][y]<11)) 
                        valid_il = 0;

                    count = 0;
                    for(int k=y+1;k<j;k++){
                        if(board[x][k]!=0)
                            count++,p=k;
                    }
                    if(count!=1) 
                        valid_r = 0;
                    count = 0,p=-1;
                    for(int k=j+1;k<y;k++){
                        if(board[x][k]!=0)
                            count++,p=k;
                    }
                    if(count!=1) 
                        valid_l = 0;
                if(i>x){
                    count=0;
                        for(int k=i-1;k>x;k--){
                            if(board[k][j]!=0)
                                count++;
                        }
                        if(count>1||(count==1&&board[x][j]<11)) 
                            valid_ju = 0;
                    if(j>y){
                        if(valid_ju && valid_r){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                        }
                        if(i-x==2&&board[x+1][y]!=0 && valid_ir){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                        }
                    }
                    else if(j<y){
                        if(valid_ju && valid_l){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                        }
                        if(i-x==2&&board[x+1][y]!=0 && valid_il){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                        }
                    }
                }

                else if (i<x){
                    count = 0;
                    for(int k=i+1;k<x;k++){
                            if(board[k][j]!=0)
                                count++;
                        }
                        if(count>1||(count==1&&board[x][j]<11)) 
                            valid_jd = 0;
                    count = 0,p=-1;
                    for(int k=i+1;k<x;k++){
                            if(board[k][y]!=0)
                                count++,p=k;
                        }
                        if(count!=1) 
                            valid_d = 0;
                    if(j>y){
                        if(valid_ir && valid_d){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                            }
                        if(valid_jd && valid_r){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                            }
                    }
                    else if(j<y){
                        if(valid_il && valid_d){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,i,y);
                            ans++;
                            }
                        if(valid_jd && valid_l){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,x,j);
                            ans++;
                            }
                    }
                    else{
                        count = 0,p=-1;
                        for(int k=i+1;k<x;k++){
                            if(board[k][y]!=0){
                                count++;
                                if(count==2)
                                    p=k;
                            }
                        }
                        if(valid && count==3 && board[p][y]>=12){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,p,y);
                            ans++;
                        }
                    }
                }
                else{
                    if(j>y){
                        int count = 0,p=-1;
                        for(int k=y+1;k<j;k++){
                            if(board[x][k]!=0){
                                count++;
                                if(count==2)
                                    p=k;
                            }
                        }
                        if(valid && count==3 && board[x][p]>=12){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,x,p);
                            ans++;
                        }
                    }
                    else{
                        count = 0,p=-1;
                        for(int k=j+1;k<y;k++){
                            if(board[x][k]!=0){
                                count++;
                                if(count==2)
                                    p=k;
                            }
                        }
                        if(valid && count==3 && board[x][p]>=12){
                            printf("Move Cannon from(%d,%d) to (%d,%d)\n",i,j,x,p);
                            ans++;
                        }
                    }
                }
            }
            else if(board[i][j] == 7){
                //soldier direction
                int direction[4][2]={-1,0,0,-1,0,1,1,0};
                for(int k=0;k<4;k++){
                    int a=i+direction[k][0];
                    int b=j+direction[k][1]; 
                    //check legal position   
                    if(a>=0&&a<10 &&b>=0&&b<9&&(board[a][b]==0 || board[a][b] >=12) &&abs(x-a)+abs(y-b)==1){
                        printf("%d)Move Soldier from(%d,%d) to (%d,%d)\n",ans+1,i,j,a,b);
                        ans++;
                    }
                }
            }

        }
    }
    
    return ans;
}