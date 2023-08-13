#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printVector(vector<int> v){

   cout<<"[";
   for(int i=0; i<v.size(); i++){
       if(i == (v.size() - 1)){
        cout<<v[i];
       }else{
        cout<<v[i]<<", ";
       }
   }
   cout<<"]"<<endl;

}

vector<int> nextGreaterBruteForce(vector<int> v){

    vector<int> res;

    for(int i=0; i<v.size()-1; i++){
        int j = 0;
        for(j=i+1; j<v.size(); j++){
            if(v[j]>v[i]){
                res.push_back(v[j]);
                break;
            }
        }
        if(j == v.size()){
            res.push_back(-1);
        }
    }
    res.push_back(-1);

    return res;
}

vector<int> nextGreaterOptimized(vector<int> v){
    
    vector<int> res;
    stack<int> stk;

    for(int i=0; i<v.size();i++){

        while(!stk.empty() && stk.top() < v[i]){
            res.push_back(v[i]);
            stk.pop();
        }
        stk.push(v[i]);
    }

    while(!stk.empty()){
        res.push_back(-1);
        stk.pop();
    }

    return res;
}

int main(){

    vector<int> v = {4, 5, 2, 25};

    vector<int> res = nextGreaterBruteForce(v);
    cout<<"==== Next Greater - Brute Force ===="<<endl;
    printVector(res);

     vector<int> res1 = nextGreaterBruteForce(v);
    cout<<"==== Next Greater - Optimized ===="<<endl;
    printVector(res1);

}