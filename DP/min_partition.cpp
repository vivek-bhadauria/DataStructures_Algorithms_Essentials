#include "print_helper.h"

/*top down approach*/
int absDiff(vector<int> arr, int n, int ts, int cs, vector<vector<int>> &cache)
{

    if (n == 0)
    {   
        cache[n][cs] = abs((ts - cs) - cs);
        return cache[n][cs];
    }
    /* pick n */
    int pick_n = absDiff(arr, n - 1, ts, cs + arr[n - 1], cache);

    /* not pick n*/
    int not_pick_n = absDiff(arr, n - 1, ts, cs, cache);

    cache[n][cs] = min(pick_n, not_pick_n);
    return cache[n][cs];
}

/*bottom up approach*/
int absDiffBU(vector<int> arr, int n, int ts, int cs, vector<vector<int>> &cache){

    for(int k=0; k<=ts; k++){
        cache[0][k] = abs(ts-2*k);
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=ts; j++){
                cache[i][j] = min(cache[i-1][j], cache[i-1][j + arr[i-1]]);
        }
    }
    return cache[n][cs];
}

int findMin(vector<int> arr)
{
    int s = 0;
    for(auto x : arr){
        s += x;
    }
    vector<vector<int>> cache(arr.size()+1, vector<int>(s+1,0));
    int res = absDiffBU(arr, arr.size(), s, 0, cache);
    return res;
    
}

int main(){

    vector<int> arr = {1, 6, 11, 5};

    int s = 0;
    for(auto x : arr){
        s += x;
    }
    vector<vector<int>> cache(arr.size()+1, vector<int>(s+1,0));
    /*int res1 = absDiff(arr, arr.size(), s, 0, cache);
    cout<<"Result with top down approach : "<<res1<<endl;*/
    int res2 = absDiffBU(arr, arr.size(), s, 0, cache);
    cout<<"Result with bottom up approach : "<<res2<<endl;
}