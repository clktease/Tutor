#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

int lcs(){

}


int main(){

    string s1,s2,s3;
    cin >>s1>>s2>>s3;

    int lcs[105][105][105]={0};
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            for(int k=0;k<s3.size();k++){
                //cout<<s1[i]<<s2[j]<<s3[k]<<endl;
                if(s1[i]==s2[j]&&s2[j]==s3[k]){
                    lcs[i+1][j+1][k+1] = lcs[i][j][k] + 1;
                  //cout<<i<<j<<k<<endl;
                }
                else{
                    lcs[i+1][j+1][k+1] = max(max(max(lcs[i][j+1][k+1],lcs[i][j][k+1]),max(lcs[i][j+1][k],lcs[i+1][j+1][k])),max(lcs[i+1][j][k+1],lcs[i+1][j+1][k]));
                }
            }
        }
    }
    cout <<lcs[s1.size()][s2.size()][s3.size()]<<endl;

    return 0;
}