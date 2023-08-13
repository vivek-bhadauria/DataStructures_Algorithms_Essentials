#include<iostream>
using namespace std;

int tillingProblem(int n, int m){
    if(n == 0){
        return 1;
    }else if(n < 0){
        return 0;
    }
    /* We have below options
    1. if we intend to take vertical option,
    then we are forced to select m tiles vertically.
    So we need to count ways of subproblem (n-m, m)
    2. If we intend to take horizontal option,
    then we need to select only 1 tile. 
    So we need to count ways of subproblem (n-1, m)
    Therefore total number of ways are counted as below */
    return tillingProblem(n-m, m) + tillingProblem(n-1,m);      
}

int main(){
    int n,m;
    cout<<"Enter N : "<<endl;
    cin>>n;
    cout<<"Enter M : "<<endl;
    cin>>m;
    int count = tillingProblem(n,m);
    cout<<"Result : "<<count<<endl;
}