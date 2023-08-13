#include<iostream>
#include<vector>
using namespace std;

void increasingNumbers(int n, vector<int> &res){
     if(n==0){
        return;
     }
     increasingNumbers(n-1, res);
     res.push_back(n);
}

vector<int> increasingNumbers(int N) {
     
     vector<int> res;
     increasingNumbers(N,res);
     return res;
    
}

int main(){

  int n;
  cout<<"Enter a number"<<endl;
  cin>>n;
  vector<int> res = increasingNumbers(n);

  cout<<"==== Printing Result Vector ===="<<endl;
  for(int i=0; i<res.size(); i++){
    cout<<res[i]<<" ";
  }
  cout<<endl;

}