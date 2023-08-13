#include<iostream>
#include<vector>
using namespace std;
 
 vector<int> WavePrint(int m, int n, int arr[10][10])
{
   vector<int> res;
    
    cout<<"===== INPUT ====="<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int i=0;
    int j=n-1;
    while(j>=0){
        
        if(i == 0){
            while(i<m){
                res.push_back(arr[i++][j]);
            }
            i=m-1;
        }else if(i==(m-1)){
            while(i>=0){
                res.push_back(arr[i--][j]);
            }
            i=0;
        }
        j--;
    }

    cout<<"===== OUTPUT ====="<<endl;
    int k=res.size();
    for(int i=0; i<k; i++){
        cout<<res[i]<<" ";
    }
    
    return res;
}

int main(){

    int a[10][10];
    int n,m = 0;
    cout<<"Enter number of rows of matrix : "<<endl;
    cin>>m;
    cout<<"Enter number of columns of matrix : "<<endl;
    cin>>n;
    
    /* input matrix elements */
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    
    WavePrint(m,n,a);

}
