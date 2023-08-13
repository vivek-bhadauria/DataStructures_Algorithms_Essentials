#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> arr){
    
   int rows = arr.size();
   
   vector<pair<int, int>> zeroCoords;

   for(int i=0; i<rows; i++){
      for(int j=0; j<rows; j++){
         if(arr[i][j] == 0){
            zeroCoords.push_back({i,j});
         }
      }
   }

   for(int i=0; i<zeroCoords.size(); i++){
    
      for(int j=0; j<rows; j++){
         arr[zeroCoords[i].first][j] = 0;
         arr[j][zeroCoords[i].second] = 0;
      }

   }

   cout<<"==== Final Output ===="<<endl;
   for(int i=0; i<rows; i++){
      for(int j=0; j<rows; j++){
         cout<<arr[i][j]<<" ";
      }
      cout<<endl;
   }

   return arr;
}

int main(){

   vector<vector<int>> v = { {5, 4, 3, 9}, 
                             {2, 0, 7, 6}, 
                             {1, 3, 4, 0}, 
                             {9, 8, 3, 4} };

    makeZeroes(v);

}