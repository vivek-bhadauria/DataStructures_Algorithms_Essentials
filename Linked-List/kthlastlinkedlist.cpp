#include<iostream>
#include "linkedlist.h"
using namespace std;

int findKthLastElement(Node* head, int k){
    Node* k_ahead_ptr = head;
    for(int i=1; i<=k; i++){
        k_ahead_ptr = k_ahead_ptr->next;
    }

    Node* curr = head;
    while(k_ahead_ptr !=NULL){
        curr = curr->next;
        k_ahead_ptr = k_ahead_ptr->next;
    }

    return curr->getData();
}

int main(){

    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    int res = findKthLastElement(list.start(), 3);

    cout<<"Kth last element : "<<res<<endl;
}