#include "print_helper.h"

/* top down approach */
int minCoinsTD(vector<int> coins, int M, vector<int> &cache)
{

    int ans = INT16_MAX;

    if (M == 0)
    {
        return 0;
    }

    if (cache[M] != INT16_MAX)
    {
        return cache[M];
    }

    for (int i = 0; i < coins.size(); i++)
    {
        if (M >= coins[i])
        {
            ans = min(ans, 1 + minCoinsTD(coins, M - coins[i], cache));
        }
    }

    cache[M] = ans == INT16_MAX ? -1 : ans;

    return cache[M];
}

/* bottom up approach with solution path */
int minCoinsBU(vector<int> coins, int M, vector<int> &cache, vector<int> &sel)
{

    cache[0] = 0;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j] && cache[i - coins[j]] != INT16_MAX)
            {
                if (1 + cache[i - coins[j]] < cache[i])
                {
                    cache[i] = 1 + cache[i - coins[j]];
                    sel[i] = coins[j];
                }
            }
        }
    }

    return cache[M] == INT16_MAX ? -1 : cache[M];
}

void traceSolutionPath(int M, vector<int> &sel)
{

    vector<int> v;
    int i = M;
    while (i != 0)
    {
        v.push_back(sel[i]);
        i -= sel[i];
    }

    /* Display solution path */
    cout << "Solution Path : ";
    displayVector(v);
}

int main()
{

    vector<int> coins = {1, 3, 7, 10};
    int M = 15;
    vector<int> cache(M + 1, INT16_MAX);
    vector<int> cache2(M + 1, INT16_MAX);
    vector<int> elems(M + 1, -1);
    cout << "Result with Top Down Approach : " << minCoinsTD(coins, M, cache) << endl;
    cout << "Result with Bottom Up Approach : " << minCoinsBU(coins, M, cache2, elems) << endl;

    traceSolutionPath(M, elems);
}