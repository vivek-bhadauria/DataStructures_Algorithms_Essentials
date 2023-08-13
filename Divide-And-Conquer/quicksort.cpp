#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int> &a, int start, int end){
    if(start==end){
        return start;
    }
    int i = start + 1;
    int j = end;
    int pivot = a[start];
    while(i<=j){
        if(a[i]>pivot && a[j]<pivot){
            swap(a[i], a[j]);
        }
        if(a[i]<pivot){
            i++;
        }
        if(a[j]>pivot){
            j--;
        }
    }
    swap(a[start], a[j]);
    return j;
}

void quickSort(vector<int> &a, int start, int end){
    if(start>=end){
        return;
    }
    int pivot = findPivot(a, start, end);
    quickSort(a, start, pivot-1);
    quickSort(a, pivot+1, end);
}

int main(){
    vector<int> a = {10,5,2,0,7,6,4};
    int pivot = findPivot(a, 0, a.size()-1);
    cout<<"Pivot index : "<<pivot<<endl;
    cout<<"==== Array after Pivot found ===="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    quickSort(a, 0, a.size()-1);
    cout<<"==== Array after Quick Sort ===="<<endl;
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}