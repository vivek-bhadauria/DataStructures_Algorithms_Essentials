#include<iostream>
using namespace std;

int friendsPairing(int n){
    if( n < 0){
        return 0;
    }else if( n <= 1){
        return 1;
    }
    return friendsPairing(n-1) + (n-1) * friendsPairing(n-2);
}

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    int count = friendsPairing(n);
    cout<<"Result : "<<count<<endl;
}