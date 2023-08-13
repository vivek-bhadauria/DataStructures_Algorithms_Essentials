#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<int>> &a, int n){
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cout<<a[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
}

bool isValidOption(vector<vector<int>> &a, int i, int j, int n, int option){

    /* check column */
    for(int k=0; k<n; k++){
        if(a[k][j] == option){
            return false;
        }
    }

    /* check row */
    for(int k=0; k<n; k++){
        if(a[i][k] == option){
            return false;
        }
    }

    /* check grid */
    i = (i/3)*3;
    j = (j/3)*3;
    for(int k=0; k<n/3; k++){
        for(int l=0; l<n/3; l++){
            if(a[i+k][j+l] == option){
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>> &a, int i, int j, int n){


    if(i==n){
        printBoard(a, n);
        return;
    }

    if(j==n){
        solveSudoku(a, i+1, 0, n);
        return;
    }

    if(a[i][j] == 0){
        for(int option = 1; option<10; option++){
            if(isValidOption(a, i, j, n, option)){
                a[i][j] = option;
                solveSudoku(a, i, j+1, n);
                a[i][j] = 0;
            }
        }
    }else{
        solveSudoku(a, i, j+1, n);
    }
}

int main(){

    vector<vector<int>> a = {
                                {5,3,0,0,7,0,0,0,0},
                                {6,0,0,1,9,5,0,0,0},
                                {0,9,8,0,0,0,0,6,0},
                                {8,0,0,0,6,0,0,0,3},
                                {4,0,0,8,0,3,0,0,1},
                                {7,0,0,0,2,0,0,0,6},
                                {0,6,0,0,0,0,2,8,0},
                                {0,0,0,4,1,9,0,0,5},
                                {0,0,0,0,8,0,0,7,0}
    };

    solveSudoku(a,0,0,a.size());
    
}