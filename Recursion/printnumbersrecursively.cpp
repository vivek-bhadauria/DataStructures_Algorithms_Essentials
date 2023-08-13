#include<iostream>
using namespace std;

void printIncreasingNumbers(int n){
    if(n==0){
        return;
    }
    printIncreasingNumbers(n-1);
    cout<<n<<" ";
}

void printDecreasingNumbers(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printDecreasingNumbers(n-1); 
}

int main(){

    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    
    cout<<"==== INCREASING NUMBERS ===="<<endl;
    printIncreasingNumbers(n);
    cout<<endl<<endl;
    cout<<"==== DECREASING NUMBERS ===="<<endl;
    printDecreasingNumbers(n);

}