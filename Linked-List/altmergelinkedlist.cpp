#include<iostream>
#include "linkedlist.h"
using namespace std;

void alternateMerge(Node* root1, Node* root2){
     Node* curr1 = root1;
     Node* curr2 = root2;
     Node* next1 = NULL;
     Node* next2 = NULL;

     while(curr1 != NULL && curr2 != NULL){

        next1 = curr1->next;
        curr1->next = curr2;

        next2 = curr2->next;
        curr2->next = next1;
    
        if(next1 == NULL && next2 != NULL){
            curr2->next = next2;
        }    
        curr1 = next1;
        curr2 = next2;
     }
}

void recursiveAlternateMerge(Node* root1, Node* root2){

    if(root1 == NULL && root2 == NULL){
        return;
    }

    
    Node* next1 = root1->next;
    root1->next = root2;
    Node* next2 = root2->next;
    root2->next = next1;

    recursiveAlternateMerge(next1, next2);

}

int main(){

    LinkedList list1;
    LinkedList list2;

    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(17);
    list1.push_back(13);
    list1.push_back(11);

    cout<<"==== LIST 1 ===="<<endl;
    list1.print();

    list2.push_back(12);
    list2.push_back(10);
    list2.push_back(2);
    list2.push_back(4);
    list2.push_back(6);

    cout<<"==== LIST 2 ===="<<endl;
    list2.print();

    /*cout<<"==== AFTER ALTERNATE MERGE ===="<<endl;
    alternateMerge(list1.start(), list2.start());
    list1.print();*/

    cout<<"==== AFTER RECURSIVE ALTERNATE MERGE ===="<<endl;
    recursiveAlternateMerge(list1.start(), list2.start());
    list1.print();

}