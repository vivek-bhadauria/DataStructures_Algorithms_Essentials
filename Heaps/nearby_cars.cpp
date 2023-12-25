#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/* basic idea of the algorithm is to evict maximum till the array traversed
and keep a list of k smallest elements till the traversed part */
void displayNearByCars(vector<int> v, priority_queue<int> max_heap, int k)
{
    for(int i=k; i<v.size(); i++){
        /* we have found a number which is smaller than the greatest in heap */
        if(v[i] < max_heap.top()){
            max_heap.pop(); /* eviction of largest number so far */
            max_heap.push(v[i]);
        }
    }

    stack<int> stk;
    while(!max_heap.empty()){
        stk.push(max_heap.top());
        max_heap.pop();
    }

    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main()
{

    vector<int> v = {5, 0, 10, 2, 6, 8, 1};
    priority_queue<int> heap; /* creating max heap */
    int k = 3;
    for (int i = 0; i < k; i++)
    {
        heap.push(v[i]);
    }
    displayNearByCars(v, heap, k);
}