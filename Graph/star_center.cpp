#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>> &v)
{
    int n = v.size();
    vector<int> indegree(n + 2, 0);
    int center = 0;

    for (auto edg : v)
    {
        for (auto node : edg)
        {
            indegree[node]++;
            if (indegree[node] == n - 1)
            {
                center = node;
            }
        }
    }

    return center;
}

int main()
{

    vector<vector<int>> graph = {{1, 2}, {2, 3}, {4, 2}};
    cout << "Center : " << findCenter(graph) << endl;
}