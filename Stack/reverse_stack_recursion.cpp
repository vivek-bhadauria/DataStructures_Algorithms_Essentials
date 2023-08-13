#include<iostream>
#include<stack>
using namespace std;


void insertAtBottomRecursive(stack<int> &s, int value){

     if(s.empty()){
        s.push(value);
        return;
     }

     int temp = s.top();
     s.pop();
     insertAtBottomRecursive(s, value);
     s.push(temp);

}

void reverseStack(stack<int> &s){

     if(s.empty()){
        return;
     }

     int temp = s.top();
     s.pop();
     reverseStack(s);
     insertAtBottomRecursive(s, temp);
}

void printStack(stack<int> s){

   while(!s.empty()){

       cout<<s.top()<<" ";
       s.pop();
   }
   cout<<endl;
}

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    printStack(s);

    reverseStack(s);

    printStack(s);

}