#include "print_helper.h"

/* top down approach */
long countCombinations(vector<int> coins, int n, int s, vector<vector<long>> &cache)
{

    if (n <= 0 || s < 0)
    {
        return 0;
    }
    if (s == 0)
    {
        cache[n][s] = 1;
        return cache[n][s];
    }
    if (cache[n][s] != 0)
    {
        return cache[n][s];
    }

    /*if we pick n-1 then amount decreases by coin[i] but n does not decrease as we still want to allow n to be picked*/
    long pick_n = countCombinations(coins, n, s - coins[n - 1], cache);
    /*in case n is not picked then amount remains same but ndecreases by 1*/
    long not_pick_n = countCombinations(coins, n - 1, s, cache);

    cache[n][s] = pick_n + not_pick_n;

    return cache[n][s];
}

/* bottom up approach */
long countCombinationsBU(vector<int> coins, int m, vector<vector<long>> &cache)
{

    int n = coins.size();
    for (int k = 1; k <= n; k++)
    {
        cache[k][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            long pick = 0;
            long not_pick = 0;
            if (j - coins[i - 1] >= 0)
            {
                pick = cache[i][j - coins[i - 1]];
            }
            not_pick = cache[i - 1][j];
            cache[i][j] = pick + not_pick;
        }
    }
    return cache[n][m];
}

int main()
{

    vector<int> coins = {1, 2, 3};
    int n = 4;
    vector<vector<long>> cache(coins.size() + 1, vector<long>(n + 1, 0));
    cout << "Input : ";
    displayVector(coins);
    cout << "N : " << n << endl;
    /*long res1 = countCombinations(coins, coins.size(), n, cache);
    cout << "Result with top down approach : " << res1 << endl;*/
    long res2 = countCombinationsBU(coins, n, cache);
    cout << "Result with bottom up approach : " << res2 << endl;
    cout << "Cache : " << endl;
    displayLongMatrix(cache);
}