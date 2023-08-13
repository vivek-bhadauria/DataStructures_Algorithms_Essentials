#include<iostream>
#include<vector>
using namespace std;

void printGrid(vector<vector<int>> &v, int rows, int cols){
   for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
          cout<<v[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
}

void copyResult(vector<vector<int>> &res, vector<vector<int>> &output, int rows, int cols){
   for(int i=0; i<rows; i++){
      for(int j=0; j<cols; j++){
           output[i][j] = res[i][j];
      }
   }
}

bool canMove(vector<string> &a, vector<vector<int>> &visited, int i, int j, int rows, int cols){

    if(i<0 || i>=rows || j<0 || j>=cols){
        return false;
    }
    if(a[i][j] == 'X'){
        return false;
    }
    if(visited[i][j] == 1){
        return false;
    }
    return true;
}

void solveRatAndMice(vector<string> &a, vector<vector<int>> &res, vector<vector<int>> &visited, vector<vector<int>> &output, int i, int j, int rows, int cols){
    if(i==rows-1 && j==cols-1){
        res[i][j] = 1;
        visited[i][j] = 1;
        printGrid(res, rows, cols);
        copyResult(res, output, rows, cols);
        res[i][j] = 0;
        visited[i][j] = 0;
        return;
    }
    if(i<0 || i>=rows || j<0 || j>=cols){
        return;
    }

    vector<int> k = {-1, 0, 1, 0};
    vector<int> l = {0, 1, 0, -1};
    
    for(int m=0; m<k.size(); m++){

        if(canMove(a, visited, i+k[m], j+l[m], rows, cols)){
            res[i+k[m]][j+l[m]] = 1;
            visited[i+k[m]][j+l[m]] = 1;
            solveRatAndMice(a, res, visited, output, i+k[m], j+l[m], rows, cols);
            res[i+k[m]][j+l[m]] = 0;
            visited[i+k[m]][j+l[m]] = 0;
        }
    }
    return;
}

int main(){
    
    vector<string> a = {"OXOO",
                        "OOOX",
                        "XOXO",
                        "XOOX",
                        "XXOO"};
    int rows = a.size();
    int cols = a[0].length();

    vector<vector<int>> res(rows, vector<int>(cols, 0));
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    vector<vector<int>> output(rows, vector<int>(cols, 0));
    
    res[0][0] = 1;
    visited[0][0] = 1;
    solveRatAndMice(a, res, visited, output, 0, 0, rows, cols);
    cout<<"==== Printing result in main ===="<<endl;   
    printGrid(output, rows, cols);

}