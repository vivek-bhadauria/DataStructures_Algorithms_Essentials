#include<iostream>
#include<vector>
using namespace std;

/* Program to print all binary strings of size n which don't have consecutive 1's */

void binaryStringsNoConsecOnes(int n, string res, int prev, vector<string> &result){
    if(n == 0){
        result.push_back(res);
        return;
    }

    /* choose 0 */
    res.append("0");
    binaryStringsNoConsecOnes(n-1, res, 0, result);
    res.pop_back();

    if(prev != 1){

        /* choose 1 */
        res.append("1");
        binaryStringsNoConsecOnes(n-1, res, 1, result);
        res.pop_back();
    }
}

vector<string> binaryStrings(int n){
    string res;
    vector<string> result;
    binaryStringsNoConsecOnes(n, res, -1, result);
    return result;
}

int main(){

    int n;
    string res;
    cout<<"Enter a number : "<<endl;
    cin>>n;
    vector<string> result;
    binaryStringsNoConsecOnes(n, res, -1, result);
    for(string elem : result){
        cout<<elem<<endl;
    }
}