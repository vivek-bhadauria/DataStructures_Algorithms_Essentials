#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    string name;
    list<string> l;

    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{

    unordered_map<string, Node *> m;

    void setDefaults(unordered_map<string, bool> &visited, bool flag)
    {
        for (auto kv : m)
        {
            visited[kv.first] = flag;
        }
    }

    void dfsHelper(string name, unordered_map<string, bool> &visited)
    {

        visited[name] = true;
        /*process node*/
        cout << name << " ";

        for (auto x : m[name]->l)
        {
            if (!visited[x])
            {
                dfsHelper(x, visited);
            }
        }
    }

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string source, string dest, bool dir = true)
    {
        m[source]->l.push_back(dest);
        if (!dir)
        {
            m[dest]->l.push_back(source);
        }
    }

    void print()
    {

        for (auto kv : m)
        {
            cout << kv.first << "-->";
            for (auto x : kv.second->l)
            {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void bfs(string city)
    {

        queue<string> q;
        unordered_map<string, bool> visited;
        setDefaults(visited, false);

        q.push(city);
        visited[city] = true;

        cout << "BFS : ";
        while (!q.empty())
        {

            /*process node*/
            string curr = q.front();
            cout << curr << " ";
            q.pop();

            for (auto x : m[curr]->l)
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

    void dfs(string name)
    {
        unordered_map<string, bool> visited;
        setDefaults(visited, false);
        cout << "DFS : ";
        dfsHelper(name, visited);
        cout << endl;
    }
};

int main()
{

    Graph g({"Delhi", "Dubai", "New York", "Paris"});

    g.addEdge("Delhi", "Dubai");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Dubai", "New York");
    g.addEdge("Paris", "New York");
    g.addEdge("New York", "Dubai");

    g.print();

    g.bfs("Delhi");

    g.dfs("Delhi");
}