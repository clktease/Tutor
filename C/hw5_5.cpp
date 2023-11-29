#include<iostream>

using namespace std;
void gcd(int32_t *e,int32_t *f){
    int a = *e,b = *f; 
    
    while(a&&b){
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    if(a>b)
        *e/=a,*f/=a;
    else
        *e/=b,*f/=b;
    return;
}
void add(int32_t a,int32_t b,int32_t c,int32_t d,int32_t *e,int32_t *f){
    *f = b*d;
    *e = a*d+c*b;
    gcd(f,e);
    return;
}
void sub(int32_t a,int32_t b,int32_t c,int32_t d,int32_t *e,int32_t *f){
    *f = b*d;
    *e = a*d-c*b;
    gcd(f,e);
    return;
}
void mul(int32_t a,int32_t b,int32_t c,int32_t d,int32_t *e,int32_t *f){
    *f = b*d;
    *e = a*c;
    gcd(f,e);
    return;
}
void div(int32_t a,int32_t b,int32_t c,int32_t d,int32_t *e,int32_t *f){
    *f = b*c;
    *e = a*d;
    gcd(f,e);
    return;
}
int main(){
    
    int32_t a,b,c,d;
    int32_t e,f;

    cin >>a>>b>>c>>d;
    
    if(b==0||d==0)
        cout<<"error"<<endl;
    add(a,b,c,d,&e,&f);
    cout<<e<<f<<endl;
    div(a,b,c,d,&e,&f);
    cout<<e<<f<<endl;
    return 0;
}