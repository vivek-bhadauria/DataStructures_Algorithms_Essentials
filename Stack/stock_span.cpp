#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpannerBruteForce(vector<int> &stocks){
	vector<int> res;
    for(int i=0; i<stocks.size(); i++){
        int j = i;
        int k = 0;
        while(j>=0 && stocks[j] <= stocks[i]){
            k++;
            j--;
        }
        res.push_back(k);
    }

    return res;
}

vector<int> stockSpannerOptimized(vector<int> &stocks){
	vector<int> res = {1};
    stack<int> temp;
    temp.push(0);
    for(int i=1; i<stocks.size(); i++){
      
        while(!temp.empty() && stocks[i] >= stocks[temp.top()]){
            temp.pop();
        }
        int lastHighIdx = temp.empty() ? -1 : temp.top();
        res.push_back(i - lastHighIdx);
        temp.push(i);
    }

    return res;
}

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

int main(){

    vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};


    cout<<"=== STOCK SPANNER - BRUTE FORCE ==="<<endl;
    printVector(stockSpannerBruteForce(stocks));

    cout<<"=== STOCK SPANNER - OPTIMIZED ==="<<endl;
    printVector(stockSpannerOptimized(stocks));


}