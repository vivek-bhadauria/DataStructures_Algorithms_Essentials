#include<iostream>
#include<vector>
using namespace std;

void printGrid(vector<vector<int>> &a, int rows, int cols){
   for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
          cout<<a[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
}

int countOfGridPaths(vector<vector<int>> &a, int i, int j, int endRow, int endCol){

    /* base case */
    if(i==endRow && j==endCol){
        /*a[i][j] = 1;
        printGrid(a, endRow+1, endCol+1);
        a[i][j] = 0;*/
        return 1;
    }
    if(i>endRow || j>endCol){
        return 0;
    }

    int rightCount = 0;
    int downCount = 0;
    if(i<=endRow && j<=endCol){

        /* choose option to move right */
        a[i][j] = 1;
        rightCount = countOfGridPaths(a, i, j+1, endRow, endCol);
        a[i][j] = 0;

        /* choose option to move down */
        a[i][j] = 1;
        downCount = countOfGridPaths(a, i+1, j, endRow, endCol);
        a[i][j] = 0;
    }
    return rightCount + downCount;
}

int main(){
   int m=0, n=0;
   cout<<"Enter no of rows : "<<endl;
   cin>>m;
   cout<<"Enter no of columns : "<<endl;
   cin>>n;
   vector<vector<int>> a(m, vector<int>(n,0));

   int result = countOfGridPaths(a, 0, 0, m-1, n-1);

   cout<<"Result : "<<endl;
   cout<<result<<endl;
}