#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int reverse(int n){
   
    stack<int> temp;
    while(n!=0){
        temp.push(n % 10);
        n = n / 10;
    }

    int res = 0;
    int pos = 1;
    while(!temp.empty()){
        res = res + temp.top() * pos;
        temp.pop();
        pos = pos * 10;
    }

    return res;
}

int reverseRecursive(int n, int res){

      if(n == 0){
        return res;
      }
      return reverseRecursive(n/10, res * 10 + n % 10);

}


int main(){

    int n = 456;

    cout<<"Res : "<< reverse(n)<<endl;

    cout<<"Res : "<< reverseRecursive(n,0)<<endl;

}