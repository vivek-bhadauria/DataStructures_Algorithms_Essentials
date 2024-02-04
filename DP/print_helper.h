#include<iostream>
#include<vector>
#include<list>
using namespace std;

void displayMatrix(vector<vector<int>> v)
{
    for (auto row : v)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

void displayLongMatrix(vector<vector<long>> v){
    for(auto row : v){
        for(auto x : row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void displayVector(vector<int> v){
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

void displayList(list<int> v){
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}