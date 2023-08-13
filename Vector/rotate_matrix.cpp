#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> &matrix){

   /* do a transpose first, so that each row has all the data required */
   int n = matrix.size();
   for(int i=0; i<n; i++){
      for(int j=i; j<n; j++){
          swap(matrix[i][j], matrix[j][i]);
      }
   }

   /* transposed matrix */
   cout<<"=== Transpose ==="<<endl;
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
   }

   /* reverse each row */
   for(int i=0; i<n; i++){
      for(int j=0, k=n-1; j<k; j++, k--){
         swap(matrix[i][j], matrix[i][k]);
      }
   }

   /* transposed matrix */
   cout<<"=== Final Output ==="<<endl;
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
   }
}

/* The idea for below method is as follows.
   1. Pick four corner points of the matrix and then place them in their final correct position
   2. Then move forward and perform same logic for the complete row
   3. Once step 2 is done, the remaining matrix to work upon contains 2 rows and 2 cols less than initial state
      i.e. first and last row are done, first col and last col are done.
*/
void rotateAlternativeComplex(vector<vector<int>> &matrix){

    int start = 0;
    int end = matrix.size()-1;

    int i = 1;

    while(i<=(matrix.size()/2)){
        for(int j=start; j<end ; j++){
            vector<pair<int, int>> v = { {start, start+j},
                                  {end-j, start},
                                  {end, end-j},
                                  {start+j, end}};

            int temp = -1;
            int k;
            for(k=0; k<v.size()-1; k++){
               if(k==0){
                  temp = matrix[v[k].first][v[k].second];
                }
                matrix[v[k].first][v[k].second] = matrix[v[k+1].first][v[k+1].second];
            }
            matrix[v[k].first][v[k].second] = temp;
        }
        start++;
        end--;
        i++;
    }

   cout<<"=== Final Output ==="<<endl;
   for(int i=0; i<matrix.size(); i++){
      for(int j=0; j<matrix.size(); j++){
          cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
   }

}

int main(){

    vector<vector<int>> arr = { {1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};

    rotateAlternativeComplex(arr);
}