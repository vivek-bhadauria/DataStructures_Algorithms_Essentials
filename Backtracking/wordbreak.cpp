#include<iostream>
#include<vector>
using namespace std;

void printOutput(vector<string> &output){
    int n = output.size();
    cout<<"[";
    for(int i=0; i<n; i++){
        if(i==n-1){
            cout<<output[i];
        }else{
            cout<<output[i]<<", ";
        }
    }
    cout<<"]"<<endl;
}

bool isPresentInDictionary(vector<string> &dictionary, string input){

    for(int i=0; i<dictionary.size(); i++){
        if(dictionary[i].compare(input) == 0){
            return true;
        }
    }
    return false;
}

int wordBreak(string input, vector<string> &dictionary, vector<string> &output){

    if(input.length() == 0){
        printOutput(output);
        return 1;
    }
    
    int count = 0;
    for(int i=0; i<input.length(); i++){
        string currString = input.substr(0,i+1);
        string remainingString = input.substr(i+1, input.length()-(i+1));

        if(isPresentInDictionary(dictionary, currString)){
            output.push_back(currString);
            count += wordBreak(remainingString, dictionary, output);
            output.pop_back();
        }       
    }
    return count;
}

int main(){

    vector<string> dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"};
    string str = "ilikesamsungmobile";
    vector<string> output;
    int count = wordBreak(str, dictionary, output);
    cout<<"Count of ways to break word : "<<count<<endl;
}