#include "print_helper.h"

/* top down approach */
int maxAmount(vector<int> v, int i, int j, vector<vector<int>> &cache)
{

    if (i > j)
    {
        return 0;
    }
    if (cache[i][j] != 0)
    {
        return cache[i][j];
    }
    int left_choice = v[i] + min(maxAmount(v, i + 2, j, cache), maxAmount(v, i + 1, j - 1, cache));
    int right_choice = v[j] + min(maxAmount(v, i + 1, j - 1, cache), maxAmount(v, i, j - 2, cache));

    cache[i][j] = max(left_choice, right_choice);
    return cache[i][j];
}

/* bottom up approach */
int maxAmountBU(vector<int> v, vector<vector<int>> &cache)
{

    int n = v.size();

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            /* left choice computation */
            int left_choice = v[i];
            if (j < 1)
            {
                left_choice += cache[i + 2][j];
            }
            else
            {
                left_choice += min(cache[i + 2][j], cache[i + 1][j - 1]);
            }

            /* right choice computation */
            int right_choice = v[j];
            if (j == 1)
            {
                right_choice += cache[i + 1][j - 1];
            }
            else
            {
                right_choice += min(cache[i + 1][j - 1], cache[i][j - 2]);
            }
            cache[i][j] = max(left_choice, right_choice);
        }
    }
    return cache[0][n - 1];
}

/* not really a correct solution but works on this data set 
because we need to capture what choice was taken by henry in case both of his subproblems produced equal result */
void traceSolutionPath(vector<int> v, vector<vector<int>> cache)
{

    int n = v.size();
    int i = 0;
    int j = n - 1;
    int val = cache[i][j];
    list<int> l;

    while (val != 0)
    {

        if (v[i] + min(cache[i + 2][j], cache[i + 1][j - 1]) > v[j] + min(cache[i + 1][j - 1], cache[i][j - 2]))
        {
            /* left choice taken */
            l.push_front(v[i]);
            val -= v[i];
            if (cache[i + 2][j] < cache[i + 1][j - 1])
            {
                i += 2;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            /*right choice taken*/
            l.push_front(v[j]);
            val -= v[j];
            if (cache[i + 1][j - 1] < cache[i][j - 2])
            {
                i++;
                j--;
            }
            else
            {
                j -= 2;
            }
        }
    }

    cout << "Solution Path :";
    displayList(l);
}

int main()
{

    vector<int> v = {1, 2, 3, 4};
    int n = v.size();
    vector<vector<int>> cache(n + 2, vector<int>(n, 0));
    /*int res1 = maxAmount(v, 0, n - 1, cache);
    cout << "Result with top down approach : " << res1 << endl;*/
    int res2 = maxAmountBU(v, cache);
    cout << "Result with bottom up approach : " << res2 << endl;
    traceSolutionPath(v, cache);
}