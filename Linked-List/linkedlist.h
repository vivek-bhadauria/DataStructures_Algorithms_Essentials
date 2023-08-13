#include<iostream>
using namespace std;

class LinkedList;

class Node{

        int data;

    public:
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        int getData(){
            return data;
        }

        void setData(int data){
            this->data = data;
        }

        ~Node(){
            if(next != NULL){
                delete next;
            }
            /*cout<<"Deleting node with data "<<data<<endl;*/
        }

    friend class LinkedList;
};

class LinkedList{

    Node* head;
    Node* tail;

    int recursiveSearchHelper(int data, Node* curr){
        if(curr == NULL){
            return -1;
        }
        if(curr->data == data){
            return 0;
        }
        int index = recursiveSearchHelper(data, curr->next);
        if(index == -1){
            return -1;
        }
        return index+1;
    }

    void recursiveReverseHelper(Node* curr_node, Node* next_node){
        if(curr_node == head){
            tail = curr_node;
            curr_node->next = NULL;
        }
        if(next_node == NULL){
            head = curr_node;
            return;
        }
        recursiveReverseHelper(next_node, next_node->next);
        next_node->next = curr_node;
    }

    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        Node* start(){
            return head;
        }

        Node* end(){
            return tail;
        }

        void push_front(int data){
            Node* node = new Node(data);
            node->next = head;
            if(head == NULL){
                tail = node;
            }
            head = node;
        }

        void push_back(int data){
            
            Node* node = new Node(data);
            if(head == NULL){ /* Case 1: list is empty */
               head = node;
            }else{ /* Case 2: list is not empty */
               tail->next = node;
            }
            tail = node;
        }

        void print(){
            Node* start = head;
            while(start != NULL){
                cout<<start->data;
                if(start->next != NULL){
                    cout<<" -> ";
                }
                start = start->next;
            }
            cout<<endl;
        }

        void insert(int pos, int data){
            if(pos == 0){
                push_front(data);
            }else{
                Node* curr = head;
                for(int i=1; (i<=pos-1 && curr != NULL); i++){
                    curr = curr->next;
                }

                /* Case 1: case may arise if position is greater than or equal to no of elements in the list.
                   In such a case we insert the node at the end */ 
                if(curr == NULL || curr->next == NULL){ 
                    push_back(data);  
                }else{/* Case 2: when the position is anywhere betwwen the start and end of the list*/
                    Node* node = new Node(data);
                    node->next = curr->next;
                    curr->next = node;
                }
            }
        }

        int search(int data){
            Node* curr = head;
            int index = 0;
            while(curr != NULL){
                if(curr->data == data){
                    return index;
                }
                index++;
                curr = curr->next;
            }
            return -1;
        }

        int recursiveSearch(int data){
            return recursiveSearchHelper(data, head);
        }

        void pop_front(){
            Node* curr = head;
            if(head == NULL){
                cout<<"Empty already !!!"<<endl;
                return;
            }
            
            head = head->next;
            
            if(curr == tail){ /* if list consist of only one element */
                tail = NULL;
            }
            curr->next = NULL;
            delete curr;
        }

        void pop_back(){
            Node* curr = head;
            if(head == NULL){
                cout<<"Empty already !!!"<<endl;
                return;
            }
            
            if(curr == tail){ /* if the list consists of only one node */
                delete curr;
                head = NULL;
                tail = NULL;
            }

            while(curr->next != tail){
                curr = curr->next;
            }
            delete tail;
            curr->next = NULL;
            tail = curr;
        }

        void delete_node(int pos){
            if(pos == 0){
                pop_front();
            }else{ 
                Node* curr = head;
                for(int i=1; i<=pos-1 && curr != NULL; i++){
                    curr = curr->next;
                }
                if(curr == NULL || curr->next == NULL){
                    /* this means that position is greater than or equal to the no of elements.
                    We delete the last node in this case */
                    pop_back();
                }else{
                    Node* node_to_del = curr->next;
                    curr->next = node_to_del->next;
                    node_to_del->next = NULL;
                    delete node_to_del; 
                }
            }
        }

        void reverse(){
            if(head == NULL){
                return;
            } 
            if(head == tail){
                return;
            }
            Node* curr_node = head;
            Node* next_node = head->next;
            Node* temp = NULL;

            while(next_node != NULL){
                if(temp == NULL){
                    tail = curr_node;
                    curr_node->next = NULL;
                }

                temp = next_node;
                next_node = next_node->next;
                temp->next = curr_node;
                curr_node = temp;
            }
            head = curr_node;
        }

        void recursiveReverse(){
             if(head == NULL){
                return;
            } 
            if(head == tail){
                return;
            }
            recursiveReverseHelper(head, head->next);
        }

        ~LinkedList(){
            if(head != NULL) {
                delete head;
                head = NULL;
                tail = NULL;
            }
        }
};

