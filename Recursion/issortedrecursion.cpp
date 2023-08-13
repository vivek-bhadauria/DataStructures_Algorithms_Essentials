#include<iostream>
using namespace std;

bool isSortedViaBackwardRecursion(int a[], int n){
    if(n==0){
        return true;
    }
    if(a[n-1] > a[n]){
        return false;
    }
    return isSortedViaBackwardRecursion(a, n-1);
}

bool isSortedViaForwardRecursion(int a[], int i, int n){

    if(i == n-1){
        return true;
    }
    if(a[i] > a[i+1]){
        return false;
    }
    return isSortedViaForwardRecursion(a, i+1, n);
}

int main(){

    int a[] = {1,2,3,4,8,6,7};
    int n = sizeof(a)/sizeof(int); 
    
    cout<<"Is Sorted via Backward Recursion : "<<isSortedViaBackwardRecursion(a,n-1)<<endl;
    cout<<"Is Sorted via Forward Recursion : "<<isSortedViaForwardRecursion(a,0,n)<<endl;
}