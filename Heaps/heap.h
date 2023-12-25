#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> v;
    bool isMaxHeap = false;

public:
    Heap()
    {
        v.push_back(-1);
    }

    bool compare(int a, int b)
    {
        if (isMaxHeap)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }

    /* Time Complexity = O(logN) */
    void heapify(int idx)
    {

        int left = 2 * idx;
        int right = 2 * idx + 1;

        int minMaxIdx = idx;
        if (left < v.size() && compare(v[minMaxIdx], v[left]))
        {
            minMaxIdx = left;
        }
        if (right < v.size() && compare(v[minMaxIdx], v[right]))
        {
            minMaxIdx = right;
        }

        if(minMaxIdx != idx){
            swap(v[minMaxIdx], v[idx]);
            heapify(minMaxIdx);
        }
    }

    /* Time Complexity = O(logN) */
    void push(int data)
    {
        v.push_back(data);
        int idx = v.size() - 1;
        int parent = idx / 2;
        while (idx > 1 && compare(v[parent], v[idx]))
        {
            swap(v[parent], v[idx]);
            idx = parent;
            parent = parent / 2;
        }
    }

    /* Time Complexity = O(logN) */
    void pop()
    {
        if (empty())
        {
            return;
        }
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }

    /* Time Complexity = O(1) */
    int top()
    {
        if (empty())
        {
            return -1;
        }
        return v[1];
    }

    void setMaxHeap(bool maxHeap){
        isMaxHeap = maxHeap;
    }
};
