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

void reverse(vector<int> &v){
    int n = v.size();
    for(int i=0, j=n-1; i<j; i++, j--){
        swap(v[i], v[j]);
    } 
}

int getMaxAreaBruteForce(vector<int> hist){
   int maxArea = -1;
   for(int i=0; i<hist.size(); i++){
        int minSoFar = hist[i];
        int k=1;
        int j=i;
        while(j>=0){
            minSoFar = min(minSoFar, hist[j]);
            maxArea = max(maxArea, max(hist[j], minSoFar * k)); 
            k++;
            j--;
        } 
   }
   return maxArea;
}

/* finding previous lower value for each index */
vector<int> findPreviousLowIndexes(vector<int> hist){
    stack<int> stk;
    vector<int> prevLowIndexes;
    
    stk.push(0);
    prevLowIndexes.push_back(-1);
 
    for(int i=1; i<hist.size(); i++){

        while(!stk.empty() && hist[stk.top()] > hist[i]){
            stk.pop();
        }
        int prevLowIndex = stk.empty() ? -1 : stk.top();
        prevLowIndexes.push_back(prevLowIndex);
        stk.push(i);
    }
    return prevLowIndexes;
}

/* finding next lower value for each index */
vector<int> findNextLowIndexes(vector<int> hist){
    
    reverse(hist);

    vector<int> nextLowIndexes = findPreviousLowIndexes(hist);
    int n = nextLowIndexes.size();
    for(int i=0; i<nextLowIndexes.size(); i++){
        nextLowIndexes[i] = n-1-nextLowIndexes[i];
    }
    
    reverse(nextLowIndexes);

    return nextLowIndexes;
}

int getMaxAreaOptimized(vector<int> hist){

    /* Intuition here is that for each index we calculate the area.
       And then we calculate the max area out of the areas found for each index.

       To find area at each index, we need to find the previous lower value for that index
       and next lower value for that index and find the area between these two indices
    */
    cout<<"Input : ";
    printVector(hist);

    /* finding previous lower value for each index */
    vector<int> left = findPreviousLowIndexes(hist);
    cout<<"Left Low : ";
    printVector(left);

    /* finding next lower value for each index */
    vector<int> right = findNextLowIndexes(hist);
    cout<<"Right Low : ";
    printVector(right);

    /* finding the maximum area */
    int maxArea = -1;
    for(int i=0; i<hist.size(); i++){
        maxArea = max( maxArea, 
                       hist[i] * (right[i] - left[i] - 1));
    }
    return maxArea;

}

int main(){

    vector<int> v = {6, 2, 5, 4, 5, 1, 6};

    int res = getMaxAreaBruteForce(v);
    cout<<res<<endl;

    int res1 = getMaxAreaOptimized(v);
    cout<<res1<<endl;
}