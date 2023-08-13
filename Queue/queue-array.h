#include<iostream>
using namespace std;

template<typename T>
class Queue{

    T* arr;
    int front;
    int rear;
    int size;
    int capacity;
    
    public:
        Queue(){
            capacity = 5;
            arr = new T[capacity];
            front = -1;
            rear = -1;
            size = 0;
        }

        bool empty(){
            return size == 0;
        }

        bool full(){
            return size == capacity;
        }

        int Size(){
            return size;
        }

        T Front(){
            return arr[front];
        }

        void push(T data){
            if(full()){
                cout<<"Queue is full!!!"<<endl;
                return;
            }
            rear = (rear + 1) % capacity;
            if(empty()){
                front = rear;
            }
            arr[rear] = data;
            size++;
        }

        void pop(){
            if(empty()){
                cout<<"Queue is empty!!!"<<endl;
                return;
            }
            front = (front + 1) % capacity;
            size--;
        }    
};