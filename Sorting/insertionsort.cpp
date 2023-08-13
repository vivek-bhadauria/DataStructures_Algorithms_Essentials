#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& a){

  int n = a.size();
  for(int i=1; i<n; i++){
    int temp = a[i];
    int j = i-1;
    while(j>=0 && a[j]>temp){
        a[j+1] = a[j];
        j = j-1;
    }
    a[j+1] = temp;
  }
}

int main(){

    vector<int> a{10,7,15,5,3};
    
    insertion_sort(a);

    cout<<"===== INSERTION SORT RESULT ====="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }

    return 0;
}