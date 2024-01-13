#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    unordered_set<int> set;
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++)
    {
        set.insert(nums1[i]);
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        if (set.find(nums2[i]) != set.end())
        {
            res.push_back(nums2[i]);
            set.erase(nums2[i]);
        }
    }

    sort(res.begin(), res.end());

    return res;
}

void printVector(vector<int> v)
{
    cout << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> res = intersection(nums1, nums2);

    cout << "Result : ";
    printVector(res);
}