#include <iostream>
using namespace std;

/* Brute force implementation - No optimization whatsoever */
int max_of_min_tree_brute_force(int a[10][10], int m, int n){

   int max_of_min_sum = -1;
   for(int i=0; i<=m-1; i++){
      for(int j=0; j<=n-1; j++){
        int sum1=0,sum2=0,sum3=0,sum4=0;

        /*Quadrant 1 Sum
          Rows - 0 to i
          Cols - 0 to j*/
        for(int k=0; k<=i; k++){
            for(int l=0; l<=j; l++){
                sum1 += a[k][l];
            }
        }

        /*Quadrant 2 Sum
          Rows - 0 to i
          Cols - j+1 to n-1*/
        for(int k=0; k<=i; k++){
            for(int l=j+1; l<=n-1; l++){
                sum2 += a[k][l];
            }
        }

        /*Quadrant 3 Sum
          Rows - i+1 to m-1
          Cols - 0 to j*/
        for(int k=i+1; k<=m-1; k++){
            for(int l=0; l<=j; l++){
                sum3 += a[k][l];
            }
        }

        /*Quadrant 4 Sum
          Rows - i+1 to m-1
          Cols - j+1 to n-1*/
        for(int k=i+1; k<=m-1; k++){
            for(int l=j+1; l<=n-1; l++){
                sum4 += a[k][l];
            }
        }

        max_of_min_sum= max(max_of_min_sum,
                            min(min(sum1,sum2), min(sum3, sum4)));

      }
   }

   return max_of_min_sum;
}

void get_intermediate_array(int a[10][10], int m, int n,int sum[10][10]){
    /*Prepare an intermediate array where intermediate sum for each i, j is stored
    as below. Suppose we know the sum till given i,j grid then we can identify sum[i][j] as below
    sum[i][j] =  a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] 
    (Note : the subtraction is done because that portion was summed up twice due to previous sums)*/
    sum[0][0] = a[0][0];

    for(int i=1; i<=n-1; i++){
        sum[0][i] = a[0][i] + sum[0][i-1];
    }   

    for(int i=1; i<=m-1; i++){
        sum[i][0] = a[i][0] + sum[i-1][0];
    }                                                                                             

    for(int i=1; i<=m-1; i++){
        for(int j=1; j<=n-1; j++){
           sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    /* Print intermediate array*/
    cout<<"==== INTERMEDIATE ARRAY ===="<<endl;
    for(int i=0; i<=m-1; i++){
        for(int j=0; j<=n-1; j++){
           cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}

int max_of_min_tree_optimized(int a[10][10], int m, int n){

    int sum[10][10] = {0};

    get_intermediate_array(a, m, n, sum);
    int max_of_min_sum = -1;
    int sum1=0, sum2=0, sum3=0, sum4=0, min_sum=9999;
    int part_i=-1, part_j=-1;
    for(int i=0; i<=m-1; i++){
        for(int j=0; j<=n-1; j++){
           sum1 = sum[i][j];
           sum2 = sum[i][n-1] - sum[i][j];
           sum3 = sum[m-1][j] - sum[i][j];
           sum4 = sum[m-1][n-1] - sum[i][n-1] - sum[m-1][j] + sum[i][j];
           min_sum = min(min(sum1,sum2), min(sum3, sum4));
           if(max_of_min_sum < min_sum){
                max_of_min_sum = min_sum;
                part_i = i;
                part_j = j;
           }
        }
    }

    cout<<"Horizontal line cut at : "<<part_i<<endl;
    cout<<"Vertical line cut at : "<<part_j<<endl;
    return max_of_min_sum;
}
int main(){

    int a[][10] = { {0,1,1,0,0,0},
                    {1,0,0,1,1,0},
                    {0,1,0,0,0,0},
                    {0,1,1,0,0,1},
                    {1,0,0,1,1,0},
                    {0,1,0,0,0,0} };
    int m = 6;
    int n = 6;

    int res1 = max_of_min_tree_brute_force(a, m, n);
    cout<<"Result - Brute Force : "<<res1<<endl;

    int res2 = max_of_min_tree_optimized(a,m,n);
    cout<<"Result - Optimized : "<<res1<<endl;
}