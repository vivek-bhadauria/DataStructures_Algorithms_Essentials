#include <iostream>
#include "heap.h"
using namespace std;

int main()
{

    /* test maxHeap */
    Heap pq;
    pq.setMaxHeap(true);
    pq.push(10);
    pq.push(80);
    pq.push(5);
    pq.push(90);
    pq.push(50);
    pq.push(60);

    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
}