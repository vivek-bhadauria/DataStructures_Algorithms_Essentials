#include "print_helper.h"

/* top down approach */
int lisHere(vector<int> v, int n, vector<int> &mem, vector<int> &sel)
{
    int ans = 1;
    int max_idx = n;
    if (n == 0)
    {
        mem[n] = 1;
        sel[n] = n;
        return mem[n];
    }
    if (mem[n] != -1)
    {
        return mem[n];
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] < v[n])
        {
            int newLen = 1 + lisHere(v, i, mem, sel);
            if (newLen > ans)
            {
                ans = newLen;
                max_idx = i;
            }
        }
    }

    sel[n] = max_idx;
    mem[n] = ans;
    return mem[n];
}

pair<int, int> lis(vector<int> v, vector<int> &mem, vector<int> &sel)
{

    int ans = 1;
    int max_idx = -1;
    for (int i = 0; i < v.size(); i++)
    {
        lisHere(v, i, mem, sel);
        if (mem[i] > ans)
        {
            ans = mem[i];
            max_idx = i;
        }
    }

    /*Display mem */
    cout << "mem : ";
    displayVector(mem);

    /*Display selection vector */
    cout << "sel : ";
    displayVector(sel);

    return {ans, max_idx};
}

void traceSolutionPath(vector<int> v, vector<int> sel, int maxIdx, int maxLen)
{

    int i = maxIdx;
    int len = maxLen;
    list<int> res;

    while (len > 0)
    {
        res.push_front(v[i]);
        i = sel[i];
        len--;
    }

    /* solution path */
    cout << "Solution path : ";
    displayList(res);
}

/* bottom up approach */
pair<int, int> lisBU(vector<int> v, vector<int> &cache, vector<int> &sel)
{
    int ans = 1;
    int maxIdx = -1;
    for (int i = 1; i < v.size(); i++)
    {
        sel[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                if (1 + cache[j] > cache[i])
                {
                    cache[i] = 1 + cache[j];
                    sel[i] = j;

                    /* track longest sequence length on update */
                    if (cache[i] > ans)
                    {
                        ans = cache[i];
                        maxIdx = i;
                    }
                }
            }
        }
    }

    /*Display cache */
    cout << "cache : ";
    displayVector(cache);

    /*Display selection vector */
    cout << "sel : ";
    displayVector(sel);

    return {ans, maxIdx};
}

int main()
{

    vector<int> v = {50, 4, 10, 8, 30, 100, 2};
    vector<int> cache(v.size(), -1);
    vector<int> sel(v.size(), -1);
    cout << "Results with Top Down Approach " << endl;
    pair<int, int> res = lis(v, cache, sel);
    cout << "Result : " << res.first << " at idx : " << res.second << endl;
    traceSolutionPath(v, sel, res.second, res.first);

    vector<int> cache2(v.size(), 1);
    vector<int> sel2(v.size(), 0);
    cout << endl
         << "Results with Bottom Up Approach " << endl;
    pair<int, int> res2 = lisBU(v, cache2, sel2);
    cout << "Result : " << res2.first << " at idx : " << res2.second << endl;
    traceSolutionPath(v, sel2, res2.second, res2.first);
}