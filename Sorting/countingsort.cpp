#include <iostream>
#include <vector>
using namespace std;

int maximum(vector<int>& a){
   int n = a.size();
   int maxNum = a[0];
   for(int i=1; i<n; i++){
      maxNum = max(maxNum, a[i]);
   }
   return maxNum;
}

void counting_sort(vector<int>& a){

  int n = a.size();
  int countArrSize = maximum(a) + 1;
  vector<int> count(countArrSize, -1);

  /*Prepare the count array with data*/
  for(int i=0; i<n; i++){
    if(count[a[i]]==-1){
        count[a[i]] = 0;
    }
    count[a[i]] = count[a[i]]+1;
  }

  /* Sort the input array using the data from count array */
  int i=0;
  for(int j=0; j<countArrSize; j++){
    if(count[j]==-1)
        continue;
    while(count[j]!=0){
        a[i] = j;
        count[j] = count[j] - 1;
        i = i + 1;
    }
  }
}

int main(){

    vector<int> a{5,8,3,1,1,2,7};
    
    counting_sort(a);

    cout<<"===== COUNTING SORT RESULT ====="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }

    return 0;
}