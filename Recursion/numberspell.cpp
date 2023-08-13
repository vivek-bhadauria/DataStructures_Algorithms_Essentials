#include<iostream>
using namespace std;

string getSpell(int n){
    string spell[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    return spell[n];
}

void spellNumber(int n){
    if(n==0){
        return;
    }
    int num = n % 10;
    spellNumber(n / 10);
    cout<<getSpell(num)<<" ";
}

int main(){

    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    spellNumber(n);
}