#include "print_helper.h"

/* top down approach */
int knapsack(vector<int> prices, vector<int> wts, int N, int W, vector<vector<int>> &cache)
{
    int inc = 0, exc = 0;
    if (N == 0 || W == 0)
    {
        return 0;
    }
    if (cache[N][W] != 0)
    {
        return cache[N][W];
    }
    exc = knapsack(prices, wts, N - 1, W, cache);
    if (W - wts[N - 1] >= 0)
    {

        inc = prices[N - 1] + knapsack(prices, wts, N - 1, W - wts[N - 1], cache);
    }
    cache[N][W] = max(inc, exc);
    return cache[N][W];
}

/* bottom up approach */
int knapsackBU(vector<int> prices, vector<int> wts, int N, int W, vector<vector<int>> &cache)
{

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cache[i][j] = cache[i - 1][j];
            if (j - wts[i - 1] >= 0)
            {
                cache[i][j] = max(cache[i - 1][j], prices[i - 1] + cache[i - 1][j - wts[i - 1]]);
            }
        }
    }

    return cache[N][W];
}

void traceSolutionPath(vector<int> prices, vector<int> wts, int N, int W, vector<vector<int>> &cache, int resultPrice)
{

    int i = N;
    int j = W;
    vector<pair<int, int>> v;

    while (resultPrice != 0)
    {
        if (prices[i - 1] + cache[i - 1][j - wts[i - 1]] > cache[i - 1][j])
        {
            v.push_back({wts[i - 1], prices[i - 1]});
            resultPrice -= prices[i - 1];
            j -= wts[i - 1];
        }
        i -= 1;
    }

    /* Display chosen values */
    for (auto x : v)
    {
        cout << x.first << " weight picked with price " << x.second << endl;
    }
    cout << endl;
}

/* bottom up approach - optimized for space to be of O(W) */
int knapsackBUOpt(vector<int> prices, vector<int> wts, int N, int W, vector<vector<int>> &cache)
{

    int k = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cache[k + 1][j] = cache[k][j];
            if (j - wts[i - 1] >= 0)
            {
                cache[k + 1][j] = max(cache[k][j], prices[i - 1] + cache[k][j - wts[i - 1]]);
            }
        }
        /*copy K+1 row to K row */
        for (int m = 0; m <= W; m++)
        {
            cache[k][m] = cache[k + 1][m];
            cache[k + 1][m] = 0;
        }
    }

    return cache[k][W];
}

int main()
{

    int N = 4;
    int W = 11;
    vector<int> wts = {2, 7, 3, 4};
    vector<int> prices = {5, 20, 20, 10};

    /* Top Down Test */
    vector<vector<int>> cache(N + 1, vector<int>(W + 1, 0));
    int res = knapsack(prices, wts, 4, 11, cache);
    cout << "Result with top down approach : " << endl;
    cout << "Cache : " << endl;
    displayMatrix(cache);
    cout << "Result : " << res << endl;

    /* Bottom Up Test */
    vector<vector<int>> cache2(N + 1, vector<int>(W + 1, 0));
    int res2 = knapsackBU(prices, wts, 4, 11, cache2);
    cout << "Result with bottom up approach : " << endl;
    cout << "Cache2 : " << endl;
    displayMatrix(cache2);
    cout << "Result : " << res2 << endl;
    traceSolutionPath(prices, wts, 4, 11, cache2, res2);

    /* Bottom Up Test Optimized */
    vector<vector<int>> cache3(2, vector<int>(W + 1, 0));
    int res3 = knapsackBUOpt(prices, wts, 4, 11, cache3);
    cout << "Result with bottom up approach : " << endl;
    cout << "Cache3 : " << endl;
    displayMatrix(cache3);
    cout << "Result : " << res3 << endl;
}