#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayKSum(vector<int> arr, int k)
{
    unordered_map<int, int> map;
    int sum = 0;
    int maxLen = -1;
    cout << k << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
        sum = sum + arr[i];
        map[sum] = i;
    }

    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (map.count(k) > 0)
        {
            maxLen = max(maxLen, map[k] + 1);
        }
        if (map.count(it->first - k) > 0)
        {
            maxLen = max(maxLen, it->second - map[it->first - k]);
        }
    }

    return maxLen;
}

int main()
{

    vector<int> v = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5};
    int k = 15;

    int res = longestSubarrayKSum(v, k);
    cout << endl
         << "Result : " << res << endl;
}