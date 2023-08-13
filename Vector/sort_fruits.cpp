#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool compareName(pair<string,int> param1, pair<string,int> param2){
    if(param1.first.compare(param2.first)<0){
        return true;
    }else{
        return false;
    }
}

bool comparePrice(pair<string,int> param1, pair<string,int> param2){
        return param1.second < param2.second;
}

vector<pair<string,int>> sortFruits(vector<pair<string,int>> v, string S){

     if(S == "price"){
        sort(v.begin(), v.begin() + v.size(), comparePrice);
     }else if (S == "name"){
        sort(v.begin(), v.begin() + v.size(), compareName);
     }
     

     for(auto point : v){
        cout<<"("<<point.first<<", "<<point.second<<")"<<endl;
     }

     return v;
}

int main(){

    vector<pair<string,int>> v1 = { {"Mango",100}, {"Guava",70}, {"Grapes",40}, {"Apple",60}, {"Banana",30} };

    string s = "name";
    v1 = sortFruits(v1, s);

    cout<<"==== After sorting in main ====";

    for(auto point : v1){
        cout<<"("<<point.first<<", "<<point.second<<")"<<endl;
     }
}

