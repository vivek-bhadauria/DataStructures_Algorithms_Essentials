#include<iostream>
using namespace std;

/* i -> current index of the array
   n -> no of elements in the array
*/
void moveMaxElement(int a[], int i, int n){
    if(i == n-1){
        return;
    }
    if(a[i] > a[i+1]){
        swap(a[i], a[i+1]);
    }
    moveMaxElement(a, i+1, n);
}

/*
 n -> no of elements in the array
*/
void bubbleSortRecursive(int a[], int n){
     if(n==1){
        return;
     }
     moveMaxElement(a, 0, n);
     bubbleSortRecursive(a, n-1);
}

int main(){
    int a[] = {1,9,7,2,8,3};
    int n = sizeof(a)/sizeof(int);
    bubbleSortRecursive(a,n);
    cout<<"==== RESULT OF BUBBLE SORT ===="<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}