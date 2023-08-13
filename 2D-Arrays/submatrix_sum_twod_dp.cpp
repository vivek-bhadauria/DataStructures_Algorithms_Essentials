#include <iostream>
#include <vector>
using namespace std;

int sum_sub_matrix(vector<vector<int>> v, int sr, int sc, int er, int ec){
    int m = v.size();
    int n = v[0].size();

    int sum[10][10] = {0};
    
    sum[0][0] = v[0][0];

    for(int i=1; i<=m-1; i++){
        sum[i][0] = v[i][0] + sum[i-1][0];
    }

    for(int i=1; i<=n-1; i++){
        sum[0][i] = v[0][i] + sum[0][i-1];
    }

    for(int i=1; i<=m-1; i++){
        for(int j=1; j<=n-1; j++){
            sum[i][j] = v[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    
    for(int i=0; i<=m-1; i++){
        for(int j=0; j<=n-1; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<sr<<endl;
    cout<<sc<<endl;
    cout<<er<<endl;
    cout<<ec<<endl;

    int res = 0;
    if(sr!=0 && sc!=0){
        res = sum[er][ec] - sum[sr-1][ec] - sum[er][sc-1] + sum[sr-1][sc-1];
    }else if( sr==0 && sc==0 ){
        res = sum[er][ec];
    }else if( sr==0 && sc!=0 ){
        res = sum[er][ec] - sum[er][sc-1];
    }else if( sr!=0 && sc==0 ){
        res = sum[er][ec] - sum[sr-1][ec];
    }
    
    return res;

}


int main(){
    vector<vector<int>> v = {   {1, 2, 3, 4, 6},
                                {5, 3, 8, 1, 2},
                                {4, 6, 7, 5, 5},
                                {2, 4, 8, 9, 4} };


    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int res = sum_sub_matrix(v, 1, 2, 3, 3);
    cout<<"Result : "<<res<<endl;
                        
}