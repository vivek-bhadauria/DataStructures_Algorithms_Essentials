#include<iostream>
using namespace std;

int powerFast(int a, int n){
    if(n==0){
        return 1;
    }
    int res = powerFast(a, n/2);
    res = res*res; 
    return n&1 ? a*res : res;
}

int powerSlow(int a, int n){
    if(n==0){
        return 1;
    }
    return a * powerSlow(a, n-1);
}

int main(){

    int a,n;
    cout<<"Enter first num"<<endl;
    cin>>a;
    cout<<"Enter second num"<<endl;
    cin>>n;
    int fastRes = powerFast(a,n);
    cout<<"Fast Power result : "<<fastRes<<endl;
    int slowRes = powerSlow(a,n);
    cout<<"Slow Power result : "<<slowRes<<endl;

}