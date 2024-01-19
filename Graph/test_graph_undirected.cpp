#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

    void dfsHelper(int i, vector<bool> &visited)
    {

        /*process node*/
        cout << i << " ";
        visited[i] = true;

        for (auto x : l[i])
        {
            if (!visited[x])
            {
                dfsHelper(x, visited);
            }
        }
    }

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j, bool dir = false)
    {
        l[i].push_back(j);
        if (!dir)
        {
            l[j].push_back(i);
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "-->";
            for (auto x : l[i])
            {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void bfs(int i)
    {

        queue<int> q;
        vector<bool> visited(v, false);

        q.push(i);
        visited[i] = true;

        cout << "BFS : ";
        while (!q.empty())
        {

            /*process node*/
            int curr = q.front();
            cout << curr << " ";
            q.pop();
            for (auto x : l[curr])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
        cout << endl;
    }

    void dfs(int i)
    {
        vector<bool> visited(v, false);
        cout << "DFS : ";
        dfsHelper(i, visited);
        cout << endl;
    }
};

int main()
{

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.print();

    g.bfs(0);

    g.dfs(0);
}