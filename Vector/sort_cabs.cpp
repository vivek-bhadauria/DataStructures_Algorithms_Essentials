#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

double distance(pair<int,int> param){
     return pow((pow(param.first, 2) + pow(param.second, 2)), 0.5);
}

bool compareDistance(pair<int,int> param1, pair<int,int> param2){
        return distance(param1) < distance(param2);
}

vector<pair<int,int>> sortCabs(vector<pair<int,int>> v){

     sort(v.begin(), v.begin() + v.size(), compareDistance);

     for(auto point : v){
        cout<<"("<<point.first<<", "<<point.second<<")";
        cout<<" -> ";
        cout<<distance(point)<<endl;
     }

     return v;
}

int main(){

    vector<pair<int,int>> v1 = { {2,3}, {1,2}, {3,4}, {2,4}, {1,4} };

    v1 = sortCabs(v1);

    cout<<"==== After sorting in main ====";

    for(auto point : v1){
        cout<<"("<<point.first<<", "<<point.second<<")";
        cout<<" -> ";
        cout<<distance(point)<<endl;
     }
}

