#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dfsHelper(int i, vector<bool> &visited, vector<vector<int>> &rooms)
{
    int c = 0;
    visited[i] = true;
    /*process node*/
    c++;

    for (auto adj : rooms[i])
    {
        if (!visited[adj])
        {
            c += dfsHelper(adj, visited, rooms);
        }
    }

    return c;
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{

    vector<bool> visited(rooms.size(), false);
    int c = 0;
    /* maintain queue for BFS traversal
    can be solved by DFS by replacing queue with a stack */
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {

        /* process node = increment counter when each node is visited */
        int curr = q.front();
        c++;
        q.pop();

        for (auto adj : rooms[curr])
        {
            if (!visited[adj])
            {
                q.push(adj);
                visited[adj] = true;
            }
        }
    }

    return c == rooms.size();

    /* Recursive DFS approach */
    /*return dfsHelper(0,visited,rooms) == rooms.size();*/
}

int main()
{

    vector<vector<int>> graph = {{1}, {2}, {3}, {}};
    string result = canVisitAllRooms(graph) ? "YES" : "NO";
    cout << result << endl;
}