#include <iostream>
using namespace std;

pair<int,int> staircase_search(int a[10][10], int m, int n, int key){

    if((key<a[0][0]) || (key>a[m-1][n-1])){
        return {-1, -1};
    }

    int i=0;
    int j=n-1;

    while(i<m && j>=0){
        if(a[i][j]==key){
            return {i,j};
        }else if(key<a[i][j]){
            j--;
        }else{
            i++;
        }
    }

    return {-1, -1};
    
}

int main(){

    //int a[10][10];
    int m,n = 0;
    int key;
    /*cout<<"Enter number of rows of matrix : "<<endl;
    cin>>m;
    cout<<"Enter number of columns of matrix : "<<endl;
    cin>>n;*/
    int a[][10] = { {10, 20, 30, 40},
          {15, 25, 35, 45},
          {27, 29, 37, 48},
          {32, 33, 39, 50}};
    m=4;
    n=4;
    /* input matrix elements */
    /*for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }*/

    /* print matrix elements */
    cout<<"========== NORMAL PRINT =========="<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Enter number to search : "<<endl;
    cin>>key;

    pair<int, int> res = staircase_search(a,m,n,key);

    cout<<"Result : {"<<res.first<<", "<<res.second<<"}"<<endl;
}