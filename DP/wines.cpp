#include "print_helper.h"
#include <algorithm>

/* top down approach */
int maxProfit(vector<int> prices, int i, int j, vector<vector<int>> &cache)
{

    if (i > j)
    {
        return 0;
    }
    int n = prices.size();
    int y = n - (j - i);
    if (cache[i][j] != 0)
    {
        return cache[i][j];
    }

    cache[i][j] = max(prices[i] * y + maxProfit(prices, i + 1, j, cache),
                      prices[j] * y + maxProfit(prices, i, j - 1, cache));
    return cache[i][j];
}

int maxProfitBU(vector<int> prices, vector<vector<int>> &cache)
{

    int n = prices.size();
    int y = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            y = n - (j - i);
            if (i < j)
            {
                cache[i][j] = max(prices[i] * y + cache[i + 1][j],
                                  prices[j] * y + cache[i][j - 1]);
            }
            else if (i == j)
            {
                cache[i][j] = prices[i] * y;
            }
        }
    }
    return cache[0][n - 1];
}

int main()
{

    vector<int> prices = {2, 3, 5, 1, 4};
    int N = prices.size();
    vector<vector<int>> cache(N + 1, vector<int>(N, 0));
    int res = maxProfit(prices, 0, N - 1, cache);
    cout << "Result with top down approach : " << res << endl;
    displayMatrix(cache);

    vector<vector<int>> cache2(N + 1, vector<int>(N, 0));
    int res2 = maxProfitBU(prices, cache2);
    cout << "Result with bottom up approach : " << res2 << endl;
    displayMatrix(cache2);

    /* Greedy approach - does not work as we may not get the correct solution */
    /*int y=1;
    int sumPrices=0, i=0, j=prices.size()-1;
    while(i<=j){
        if(prices[i] < prices[j]){
            sumPrices += prices[i] * y;
            i++;
        }else{
            sumPrices += prices[j] * y;
            j--;
        }
        y++;
    }
    cout<<endl<<"Result with Greedy approach : "<<sumPrices;*/
}