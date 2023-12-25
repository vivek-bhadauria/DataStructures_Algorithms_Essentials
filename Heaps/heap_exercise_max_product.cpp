#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int k = 2;
    int res = 1;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < k; i++)
    {
        min_heap.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    while (!min_heap.empty())
    {
        res = res * (min_heap.top() - 1);
        min_heap.pop();
    }

    return res;
}

int main()
{

    vector<int> v = {3, 4, 5, 2};
    cout << endl
         << "Result : " << maxProduct(v);
}