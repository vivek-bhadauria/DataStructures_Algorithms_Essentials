#include<iostream>
#include<vector>
using namespace std;

int findFirstOccurrence(int a[], int i, int n, int key){
    if(i == n){
        return -1;
    }else if(a[i] == key){
        return i;
    }
    return findFirstOccurrence(a, i+1, n, key);
}

/* Better Recursion based approach */
int findFirstOccurrenceAlternate(int a[], int n, int key){
    if(n == 0){
        return -1;
    }else if(a[0] == key){
        return 0;
    }
    int subArrayIndex = findFirstOccurrenceAlternate(a+1, n-1, key);
    if(subArrayIndex == -1){
        return subArrayIndex;
    }
    return subArrayIndex + 1;
}

int findLastOccurrence(int a[], int n, int key){
    if(n==0){
        return -1;
    }else if(a[n-1] == key){
        return n-1;
    }
    return findLastOccurrence(a, n-1, key);
}

/* Better Recursion based approach */
int findLastOccurrenceAlternate(int a[], int n, int key){
    if(n==0){
        return -1;
    }
    int subArrayLastIndex = findLastOccurrenceAlternate(a+1, n-1, key);
    if(subArrayLastIndex != -1){
        return subArrayLastIndex + 1;
    }else if(a[0] == key){
            return 0;
    }
    return -1;
}

void findAllOccurence(int key, vector<int> v, int currentIndex, vector<int> &result){
    if(v.size() == 0){
        return;
    }
    if(v[0] == key){
        result.push_back(currentIndex);
    }
    vector<int> subV(v.begin()+1, v.end());
    findAllOccurence(key, subV, currentIndex + 1, result); 
    
}

vector<int> findAllOccurences(int k, vector<int> v){
    
    vector<int> result; 
    findAllOccurence(k,v,0,result);
    for(int i=0,j=result.size()-1; i<j; i++,j--){
        swap(v[i],v[j]);
    }
    return result;
}

int main(){

    int a[] = {8,1,6,3,9,2,8,4,1,2,3,6,8};
    int n = sizeof(a)/sizeof(int);
    int key = 6;
    int firstOccurIndex = findFirstOccurrence(a,0,n,key);
    cout<<"First Occurence Index : "<<firstOccurIndex<<endl;
    int firstOccurIndexAlt = findFirstOccurrenceAlternate(a,n,key);
    cout<<"First Occurence Alternate Index : "<<firstOccurIndexAlt<<endl;
    int lastOccurIndex = findLastOccurrence(a,n,key);
    cout<<"Last Occurence Index : "<<lastOccurIndex<<endl;
    int lastOccurIndexAlt = findLastOccurrenceAlternate(a,n,key);
    cout<<"Last Occurence Alternate Index : "<<lastOccurIndexAlt<<endl;

    vector<int> v = {1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9};
    vector<int> res = findAllOccurences(3,v);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

}