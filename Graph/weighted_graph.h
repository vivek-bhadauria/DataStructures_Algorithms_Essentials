#include <iostream>
#include <list>
using namespace std;

class WeightedGraph
{
public:
    int v;
    list<pair<int, int>> *l;

    WeightedGraph(int v)
    {
        this->v = v;
        l = new list<pair<int, int>>[v];
    }

    void addEdge(int i, int j, int w, bool dir = false)
    {
        l[i].push_back({w, j});
        if (!dir)
        {
            l[j].push_back({w, i});
        }
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "-->";
            for (auto kv : l[i])
            {
                cout << kv.second << ":" << kv.first << " , ";
            }
            cout << endl;
        }
    }
};