#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& a){

  int n = a.size();
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
        if(a[i]>a[j]){
            swap(a[i], a[j]);
        }
    }
  }
}

int main(){

    vector<int> a{10,7,15,5,3};
    
    selection_sort(a);

    cout<<"===== SELECTION SORT RESULT ====="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }

    return 0;
}