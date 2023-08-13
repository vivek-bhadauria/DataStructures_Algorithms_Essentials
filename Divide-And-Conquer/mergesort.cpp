#include<iostream>
#include<vector>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b){
    vector<int> c;
    int m = a.size();
    int n = b.size();
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(a[i] < b[j]){
            c.push_back(a[i++]);
        }else{
            c.push_back(b[j++]);
        }
    }
    while(i < m){
        c.push_back(a[i++]);
    }
    while(j < n){
        c.push_back(b[j++]);
    }
    return c;
}

vector<int> mergeSort(vector<int> input, int start, int end){

    if(start==end){
        vector<int> res;
        res.push_back(input[start]);
        return res;
    }
    int mid = (start + end)/2;
    vector<int> a = mergeSort(input, start, mid);
    vector<int> b = mergeSort(input, mid+1, end);
    vector<int> c = merge(a,b);
    return c;
}
int main(){
    vector<int> a = {1,5,10,11,12,13};
    vector<int> b = {2,3,4,7,8};
    
    vector<int> c = merge(a,b);

    cout<<"==== Merge result ===="<<endl;
    for(int i=0; i<c.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    vector<int> input = {1,19,12,3,2,8,5,6};
    vector<int> res = mergeSort(input, 0, input.size()-1);
    cout<<"==== Merge Sort result ===="<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}