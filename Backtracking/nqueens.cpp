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

bool isLegalMove(vector<vector<int>> &a, int i, int j, int n){

    /* check if there is an attacking queen in that column */
    for(int k=0; k<=i; k++){
       if(a[k][j]){
          return false;
       }
    }

    /* check if there is an attacking queen in the diagonal*/

    /* check in left upper diagonal */
    int k = i;
    int l = j; 
    while(k>=0 && l>=0){
        if(a[k][l]){
            return false;
        }
        k--;
        l--;
    }

    /* check in right upper diagonal */
    k = i;
    l = j; 
    while(k>=0 && l<n){
        if(a[k][l]){
            return false;
        }
        k--;
        l++;
    }

    return true;
}

/* Better way for n queens problem
   1. Count number of ways
   2. Print all solutions */
int solveNqueens(vector<vector<int>> &a, int i, int n){

    if(i==n){
        //printBoard(a,n);
        return 1;
    }

    int count = 0;
    for(int j=0; j<n; j++){
        if(isLegalMove(a,i,j,n)){
            a[i][j] = 1;
            count += solveNqueens(a,i+1,n);
            a[i][j] = 0;
        }
    }
    return count;
}

int main(){

    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n,0));

    cout<<"Result : "<<solveNqueens(a,0,n)<<endl;

}