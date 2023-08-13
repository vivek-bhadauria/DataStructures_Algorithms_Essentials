#include<iostream>
using namespace std;

void permutation(string &input, string &result, int currentIndex, int length){

    /* base case */
    if(currentIndex == length){
        cout<<result<<endl;
    }

    /* recursive case */
    for(int i=currentIndex; i<length; i++){

        result.push_back(input.at(i));
        swap(input[currentIndex], input[i]);
        permutation(input, result, currentIndex+1, length);
        swap(input[currentIndex], input[i]);
        result.pop_back();
    }
}

int main(){

    string input = "abc";
    string result = "";
    cout<<"==== Permutations ===="<<endl;
    permutation(input, result, 0, input.length());
}