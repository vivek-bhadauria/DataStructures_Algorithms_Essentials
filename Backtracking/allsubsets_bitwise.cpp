#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void printSubSet(int n, string a){
    string currSubset = "";
    int i=0;
    while(n!=0){
        if(n&1){
           currSubset = currSubset + a[i];
        }
        i++;
        n=n >>1;
    }
    cout<<currSubset<<endl;
}

void printAllSubsets(string a){
    int n = a.size();
    int numSubSets = pow(2,n);

    for(int i=0; i<numSubSets; i++){
        printSubSet(i,a);
    }
}

int main(){

    string a = "abc";
    printAllSubsets(a);
}