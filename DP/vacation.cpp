#include "print_helper.h"

/* top down approach */
int sumPoints(vector<int> a, vector<int> b, vector<int> c, int n, int p, vector<vector<int>> &cache)
{

    /* picking will be specified as below
       a->1
       b->2
       c->3
    */
    if (n == 0)
    {
        return 0;
    }
    if (cache[n][p] != 0)
    {
        return cache[n][p];
    }
    int pick_a = 0, pick_b = 0, pick_c = 0;

    /* pick a */
    if (p != 1)
    {
        pick_a = a[n - 1] + sumPoints(a, b, c, n - 1, 1, cache);
    }
    /* pick b */
    if (p != 2)
    {
        pick_b = b[n - 1] + sumPoints(a, b, c, n - 1, 2, cache);
    }
    /* pick c */
    if (p != 3)
    {
        pick_c = c[n - 1] + sumPoints(a, b, c, n - 1, 3, cache);
    }

    cache[n][p] = max(pick_a, max(pick_b, pick_c));
    return cache[n][p];
}

/* bottom up approach */
int sumPointsBU(vector<int> a, vector<int> b, vector<int> c, vector<vector<int>> &cache)
{
    int n = a.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            int pick_a = 0;
            int pick_b = 0;
            int pick_c = 0;

            /* pick a */
            if (j != 1)
            {
                pick_a = a[i - 1] + cache[i - 1][1];
            }
            /* pick b */
            if (j != 2)
            {
                pick_b = b[i - 1] + cache[i - 1][2];
            }
            /* pick c */
            if (j != 3)
            {
                pick_c = c[i - 1] + cache[i - 1][3];
            }

            cache[i][j] = max(pick_a, max(pick_b, pick_c));
        }
    }

    return cache[n][0];
}

int findMaxActivity(vector<int> a, vector<int> b, vector<int> c, vector<vector<int>> &cache, int i, int curr)
{
    int j = -1;
    int maxVal = INT16_MIN;
    for (int k = 1; k <= 3; k++)
    {
        if (k != curr && k == 1 && (a[i - 1] + cache[i - 1][k]) > maxVal)
        {
            maxVal = a[i - 1] + cache[i - 1][k];
            j = k;
        }
        if (k != curr && k == 2 && (b[i - 1] + cache[i - 1][k]) > maxVal)
        {
            maxVal = b[i - 1] + cache[i - 1][k];
            j = k;
        }
        if (k != curr && k == 3 && (c[i - 1] + cache[i - 1][k]) > maxVal)
        {
            maxVal = c[i - 1] + cache[i - 1][k];
            j = k;
        }
    }
    return j;
}

void traceSolutionPath(vector<int> a, vector<int> b, vector<int> c, vector<vector<int>> &cache)
{
    int n = a.size();
    int i = n;
    int j = 0;
    int points = cache[n][0];
    list<int> l;

    while (points != 0)
    {

        int maxAct = findMaxActivity(a, b, c, cache, i, j);
        if (maxAct == 1)
        {
            l.push_front(a[i - 1]);
            points -= a[i - 1];
        }
        else if (maxAct == 2)
        {
            l.push_front(b[i - 1]);
            points -= b[i - 1];
        }
        else if (maxAct == 3)
        {
            l.push_front(c[i - 1]);
            points -= c[i - 1];
        }
        i--;
        j = maxAct;
    }

    cout << "Solution Path : ";
    displayList(l);
}

int vacation(vector<int> a, vector<int> b, vector<int> c)
{
    int n = a.size();
    vector<vector<int>> cache(n + 1, vector<int>(4, 0));
    // int res = sumPoints(a, b, c, n, 0, cache);
    int res = sumPointsBU(a, b, c, cache);
    cout << "a : ";
    displayVector(a);
    cout << "b : ";
    displayVector(b);
    cout << "c : ";
    displayVector(c);
    cout << "Cache : ";
    displayMatrix(cache);
    traceSolutionPath(a, b, c, cache);
    return res;
}

int main()
{

    vector<int> a = {10, 20, 30};
    vector<int> b = {40, 50, 60};
    vector<int> c = {70, 80, 90};

    int n = a.size();
    vector<vector<int>> cache(n + 1, vector<int>(4, 0));
    cout << "a : ";
    displayVector(a);
    cout << "b : ";
    displayVector(b);
    cout << "c : ";
    displayVector(c);
    /*int res1 = sumPoints(a, b, c, n, 0, cache);
    cout << "Result with top down approach : " << res1 << endl;*/
    int res2 = sumPointsBU(a, b, c, cache);
    cout << "Result with bottom up approach : " << res2 << endl;
    cout << "Cache : " << endl;
    displayMatrix(cache);
    traceSolutionPath(a, b, c, cache);
}
