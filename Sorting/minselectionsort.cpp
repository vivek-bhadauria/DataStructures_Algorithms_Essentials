#include <iostream>
#include <vector>
using namespace std;

void min_selection_sort(vector<int>& a){

  int n = a.size();
  for(int i=0; i<n-1; i++){
    int min = a[i+1];
    int minIndex = i+1;
    for(int j=i+1; j<n; j++){
        if(a[j]<min){
            min = a[j];
            minIndex = j;
        }
    }
    if(a[i]>min){
        swap(a[i], a[minIndex]);
    }
  }
}

int main(){

    vector<int> a{10,7,15,5,3};
    
    min_selection_sort(a);

    cout<<"===== MIN SELECTION SORT RESULT ====="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }

    return 0;
}