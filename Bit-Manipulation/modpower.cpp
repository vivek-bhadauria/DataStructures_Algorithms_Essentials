#include<iostream>
#include<vector>
using namespace std;

int power(int x, int y, int mod){

    int p = x;
    int res = 1;
    while(y!=0){
        if(y&1){
            res = (res * p) % mod;
        }
        p = (p * p) % mod;
        y = y>>1;
    }

    return res % mod;
}

int main() {

        cout<<"Mod power : "<<power(12, 25, 10007)<<endl;
}