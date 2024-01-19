#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int i, vector<int> &path, vector<vector<int>> &allPaths, vector<vector<int>> graph)
{

    int n = graph.size();
    /*process node*/
    path.push_back(i);

    if (i == (n - 1))
    {
        /*print the current path*/
        for (auto i : path)
        {
            cout << i << ",";
        }
        cout << endl;

        allPaths.push_back(path);
    }

    for (auto adj : graph[i])
    {
        dfsHelper(adj, path, allPaths, graph);
        /* need to remove the node from the path when backtracking */
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> allPaths;
    vector<int> path;
    dfsHelper(0, path, allPaths, graph);
    return allPaths;
}

int main()
{

    vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> graph2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    cout << "Graph1 Paths " << endl;
    allPathsSourceTarget(graph1);
    cout << "Graph2 Paths " << endl;
    allPathsSourceTarget(graph2);
}