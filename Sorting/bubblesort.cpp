#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& a){

  int n = a.size();
  for(int i=1; i<n; i++){
    for(int j=0; j<n-i; j++){
        if(a[j]>a[j+1]){
            /*Swap*/
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
  }
}

int main(){

    vector<int> a{10,7,15,5,3};
    
    bubble_sort(a);

    cout<<"===== BUBBLE SORT RESULT ====="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }

    return 0;
}