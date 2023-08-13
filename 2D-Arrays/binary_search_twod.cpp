#include <iostream>
using namespace std;

pair<int,int> binary_search_twod(int a[10][10], int m, int n, int key){

    if((key<a[0][0]) || (key>a[m-1][n-1])){
        return {-1, -1};
    }

    /* Finding the row index*/
    int startRow=0;
    int endRow=m-1;
    int startCol=0;
    int endCol=n-1;
    
    while(startRow <= endRow){
        int midRow = (startRow + endRow)/2;
        cout<<"Currently on Element : "<<a[midRow][0]<<endl;
        if(key == a[midRow][0]){
            return {midRow,0};
        }
        if(key < a[midRow][0]){
            endRow = midRow-1;
        }else if (key > a[midRow][endCol]){
            startRow = midRow + 1;
        }else{
            /* Binary search on effective 1D array */
            int start = 0;
            int end = endCol;
            while(start<=end){
                int midCol = (start + end)/2;
                if(a[midRow][midCol]==key){
                    return {midRow, midCol};
                }else if(key < a[midRow][midCol]){
                    end = midCol - 1;
                }else{
                    start = midCol + 1;
                }
            }
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
    int a[][10] = { {10, 11, 12, 13},
          {20, 21, 22, 23},
          {30, 31, 32, 33},
          {40, 41, 42, 43}};
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

    pair<int, int> res = binary_search_twod(a,m,n,key);

    cout<<"Result : {"<<res.first<<", "<<res.second<<"}"<<endl;
}