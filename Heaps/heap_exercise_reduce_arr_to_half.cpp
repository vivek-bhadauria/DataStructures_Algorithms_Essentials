#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minSetSize(vector<int> &arr)
{

    /*storage used because of this is very high */
    vector<int> count_arr(100000, 0);
    vector<int> num;
    priority_queue<int> max_heap;
    int curr_size = arr.size();
    int half_size = curr_size / 2;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        num.push_back(arr[i]);
        count_arr[arr[i]]++;
    }

    for (int i = 0; i < num.size(); i++)
    {
        max_heap.push(count_arr[num[i]]);
    }

    while (curr_size > half_size)
    {
        count++;
        curr_size = curr_size - max_heap.top();
        max_heap.pop();
    }

    return count;
}

int main()
{

    vector<int> v = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    cout << endl
         << "Result : " << minSetSize(v) << endl;
}