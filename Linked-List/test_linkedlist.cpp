#include<iostream>
#include "linkedlist.h"
using namespace std;

int main(){

    LinkedList list;
    list.push_front(2); 
    list.push_front(1);
    list.push_back(3);
    list.push_back(4);

    list.print();

    list.pop_front();
    list.print();

    list.pop_back();
    list.print();

    list.push_front(1);
    list.push_back(4);
    list.print();

    list.insert(2, 31);
    list.print();

    list.insert(5, 32);
    list.print();

    list.insert(10, 33);
    list.print();

    list.delete_node(2);
    list.print();

    list.delete_node(5);
    list.print();

    cout<<"3 found at index : "<<list.search(3)<<endl;

    cout<<"3 found at index : "<<list.recursiveSearch(3)<<endl;

    cout<<"==== Iterative Reverse & Reverse Of Reverse ===="<<endl;
    list.reverse();
    list.print();

    list.reverse();
    list.print();

    cout<<"==== Recursive Reverse & Reverse Of Reverse ===="<<endl;
    list.recursiveReverse();
    list.print();

    list.recursiveReverse();
    list.print();

}