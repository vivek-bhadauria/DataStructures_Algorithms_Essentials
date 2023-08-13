#include<iostream>
#include<vector>
using namespace std;

int xoring(vector<int> v){

    int res = v[0];
    for(int i=1; i<v.size(); i++){
          res = res ^ v[i];
    } 
    return res;
}

int main(){

    vector<int> v = { 1, 2, 3, 1, 4, 2, 3 };
    int res = xoring(v);
    cout<<"Result : "<<res<<endl;
}