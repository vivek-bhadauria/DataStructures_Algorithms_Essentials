#include <iostream>
using namespace std;

void print_spiral_matrix(int a[10][10], int n, int m, int row, int col){
    int startRow, i = row;
    int startCol, j = col;
    int endRow = n-1;
    int endCol = m-1;
    int count = 0;

    while((startRow <= endRow) && (startCol <= endCol) && (count < (n*m))){

        
        /* print from left to right */
        while(count<(n*m) && j <= endCol){
            cout<<a[i][j++]<<" ";
            count++;
        }
        i++;
        j--;
        startRow++;

       /* print from top to down */
       while(count<(n*m) && i <= endRow){
            cout<<a[i++][j]<<" ";
            count++;
       }
       i--;
       j--;
       endCol--;

       /* print from right to left */
       while(count<(n*m) && j >= startCol){
            cout<<a[i][j--]<<" ";
            count++;
       }
       i--;
       j++;
       endRow--;

       /* print from down to up */
       while(count<(n*m) && i >= startRow){
            cout<<a[i--][j]<<" ";
            count++;
       }
       i++;
       j++;
       startCol++;

    }

}

int main(){

    int a[10][10];
    int n,m = 0;
    cout<<"Enter number of rows of matrix : "<<endl;
    cin>>n;
    cout<<"Enter number of columns of matrix : "<<endl;
    cin>>m;
    
    /* input matrix elements */
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    /* print matrix elements */
    cout<<"========== NORMAL PRINT =========="<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"========== SPIRAL PRINT =========="<<endl;
    print_spiral_matrix(a, n, m, 0, 0);
}