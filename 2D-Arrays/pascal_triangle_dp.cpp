#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printPascal(int n)
{
    int res[10][10] = {0};
    for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
        if(j==1 || j==i){
            res[i][j] = 1;
        }else{
            res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
      }
   }

   /* Setup Pascal's Triangle in vector */
   vector<vector<int>> fin_res;
   for(int i=1; i<=n; i++){
      vector<int> part_res;
      for(int j=1; j<=i; j++){
         part_res.push_back(res[i][j]);
      }
      fin_res.push_back(part_res);
   }

   /* Print Pascal's Triangle vector */
   for(int i=0; i<fin_res.size(); i++){
      for(int j=0; j<fin_res[i].size(); j++){
         cout<<fin_res[i][j]<<" ";
      }
      cout<<endl;
   }
    
   return fin_res;
}

void print_pascal_triangle(int n){

   int a[][10] = {0};
   for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
        if(j==1 || j==i){
            a[i][j] = 1;
        }else{
            a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
      }
   }

   /* Print Pascal's Triangle */
   for(int i=1; i<=n; i++){
      for(int j=1; j<=i; j++){
         cout<<a[i][j]<<" ";
      }
      cout<<endl;
   }
}

int main(){

    int n;
    cout<<"Enter a number : "<<endl;
    cin>>n;

    printPascal(n);

}