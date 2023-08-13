#include <iostream>
#include "linkedlist.h"
using namespace std;

void bubbleSort(Node *head)
{
    if(head->next == NULL){ /*if list has only one element, its already sorted*/
        return;
    }
    Node *curr = head;
    Node* fixed_ptr = NULL;

    while (curr != fixed_ptr)
    {
        Node *first_ptr = curr;
        Node *second_ptr = curr->next;

        while (second_ptr != fixed_ptr)
        {
            if (first_ptr->getData() > second_ptr->getData())
            {
                int temp = first_ptr->getData();
                first_ptr->setData(second_ptr->getData());
                second_ptr->setData(temp);
            }
            first_ptr = first_ptr->next;
            second_ptr = second_ptr->next;
        }

        fixed_ptr = first_ptr;
    }
}

int main(){

    LinkedList list;
    list.push_back(10);
    list.push_back(30);
    list.push_back(20);
    list.push_back(5);

    cout<<"==== LIST BEFORE SORT ===="<<endl;
    list.print();

    bubbleSort(list.start());

    cout<<"==== LIST AFTER SORT ===="<<endl;
    list.print();
}