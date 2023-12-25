#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Pair
{
public:
    int x;
    int y;
};

class PairCompare
{

public:
    bool operator()(Pair a, Pair b)
    {

        return a.y == b.y ? a.x > b.x : a.y > b.y;
    }
};

int find_last_index_of_one(vector<int> v, int i, int j)
{

    if (i > j)
    {
        return -1;
    }
    int mid = (i + j) / 2;
    if (v[mid] == 1 && mid == v.size() - 1)
    {
        return mid;
    }
    else if (v[mid] == 1 && v[mid + 1] == 0)
    {
        return mid;
    }
    else if (v[mid] == 1)
    {
        return find_last_index_of_one(v, mid + 1, j);
    }
    else
    {
        return find_last_index_of_one(v, i, mid);
    }
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int count;
    priority_queue<Pair, vector<Pair>, PairCompare> min_heap;
    vector<int> res;
    for (int i = 0; i < mat.size(); i++)
    {
        count = find_last_index_of_one(mat[i], 0, mat[i].size() - 1) + 1;
        Pair pair;
        pair.x = i;
        pair.y = count;
        min_heap.push(pair);
    }

    while (k > 0)
    {

        /*cout << min_heap.top().x << " ";*/
        res.push_back(min_heap.top().x);
        min_heap.pop();
        k--;
    }

    return res;
}

void printVector(vector<int> v)
{

    cout << endl;
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{

    vector<vector<int>> mat = {{1, 0, 0, 0},

                               {1, 1, 1, 1},

                               {1, 0, 0, 0},

                               {1, 0, 0, 0}};

    vector<int> res = kWeakestRows(mat, 2);
    printVector(res);
}