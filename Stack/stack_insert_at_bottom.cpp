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

void insertAtBottom(stack<int> &stk, int value){

    stack<int> temp; 
    while(!stk.empty()){
        temp.push(stk.top());
        stk.pop();
    }
    
    stk.push(value);

    while(!temp.empty()){
        stk.push(temp.top());
        temp.pop();
    }

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

    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"==== Stack before insert ===="<<endl;
    printStack(s);

    insertAtBottom(s,1);

    cout<<"==== Stack after insert ===="<<endl;
    printStack(s);

    insertAtBottomRecursive(s, 0);

    cout<<"==== Stack after insert recursive ===="<<endl;
    printStack(s);

}