#include<iostream>
#include "queue-array.h"
//#include "queue-linked-list.h"
#include<queue>
using namespace std;

template<typename T>
class StackQ{

    queue<T> q1;
    queue<T> q2;

    public:
        bool empty(){
            return q1.empty() && q2.empty();
        }

        void push(T data){
            q1.push(data);
        }

        void pop(){
            /* Put all elements except the last element from Q1 in Q2.
               Pop the last element in Q1*/
            while(!q1.empty()){
                if(q1.size() == 1){
                    q1.pop();
                }else{
                    q2.push(q1.front());
                    q1.pop();
                }
            }

            /* Put remaining eements back in Q1 */
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }

        T top(){
            /* Put all elements except the last element from Q1 in Q2.
               Pop the last element in Q1*/
            T temp;
            while(!q1.empty()){
                if(q1.size() == 1){
                    temp = q1.front();
                }
                q2.push(q1.front());
                q1.pop();
            }

            /* Put remaining eements back in Q1 */
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }

            return temp;
        }
};

void testArrayQueue(){

    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();
    q.pop();
    q.pop();
    
    q.push(4);
    q.push(5);

    q.pop();
    q.pop();
    
    q.push(6);
    q.push(7);
    q.push(8);

    q.pop();
    q.pop();
    q.pop();

    q.push(9);
    q.push(10);
    q.push(11);

    while(!q.empty()){
        cout<<q.Front()<<" ";
        q.pop();
    }
}

void testLinkedListQueue(){

    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.Front()<<" ";
        q.pop();
    }

}

int main(){

    testArrayQueue();
    cout<<endl;
    testLinkedListQueue();
    cout<<endl;

    cout<<"==== Testing Stack built with 2 Queues ===="<<endl;
    StackQ<int> stk;

    stk.push(1);
    stk.push(2);
    stk.push(3);

    while (!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    



}