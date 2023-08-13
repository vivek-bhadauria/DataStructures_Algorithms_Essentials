#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){

    queue<char> q;
    vector<int> v(26,0);
    vector<char> res;
    if(str.empty()){
        return res;
    }
    
    /* the first element will be non repeating*/
    q.push(str[0]);
    v[str[0] % 'a'] = 1;
    res.push_back(str[0]);
    
    for(int i=1; i<str.size(); i++){

        int j = 'a';
        int k = str[i] % j;
       
        v[k] = v[k] + 1;

        while(!q.empty() && v[q.front()%j] > 1){
            q.pop();
        }

        if(!q.empty()){
            res.push_back(q.front());
        } else if(v[k] == 1){
            res.push_back(str[i]);
        } else {
            res.push_back('0');
        }
        q.push(str[i]);
    }

    return res;
}

int main(){

    vector<char> str{'a', 'a', 'b', 'c'};

    vector<char> res = firstnonrepeating(str);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }

    return 0;
}