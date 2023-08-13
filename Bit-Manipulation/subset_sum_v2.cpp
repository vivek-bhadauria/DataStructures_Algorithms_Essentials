#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

int fastPower(int a, int b){

    int res = 1;
    int power = a;

    while(b!=0){
        if(b&1){
           res = res * power;
        }
        power = power * power;
        b = b>>1;
    }

    return res;

}

int binary_search(vector<int> num, int start, int end, int key){

    while(start<end){
        int mid = (start + end)/2;
        if(key == num[mid]){
            return mid;
        }else if(key < num[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    return -1;
}

/* Time complexity of this method = O(logN) */
int calculate_subset_sum(int sub_set_bit_seq, vector<int> num){
    int index = 0;
    int sum = 0;
    while(sub_set_bit_seq!=0){

         if(sub_set_bit_seq&1){
            sum = sum + num[index];
         }
         index++;
         sub_set_bit_seq = sub_set_bit_seq>>1; 
    }
    return sum;
}

vector<bool> subsetSum_highComplexity(vector<int> num, vector<int> query)
{
    vector<bool> res;
    int N = query.size();
    vector<int> sum_arr;

    /*
    Overall time complexity for this method comes out to be as below
    Time Complexity =  2^N * logN + N * 2^N + M * N
                    => O(N * 2^N)
    */
    /* Create an interim sum_arr which consists of sum of all subsets */
    int no_of_subsets = fastPower(2, num.size());

    /* Time complexity for this loop is 2^N * logN (for calculate_subset_sum())*/
    for(int i=0; i<no_of_subsets; i++){
        int sum_subset = calculate_subset_sum(i, num);
        sum_arr.push_back(sum_subset);
    }

    /* Time complexity 2^N * log2^N => N * 2^N */
    sort(sum_arr.begin(), sum_arr.end());

    cout<<"==== Interim sum array ===="<<endl;
    for(int i=0; i<sum_arr.size(); i++){
        cout<<sum_arr[i]<<" ";
    }
    cout<<endl;

    /*Time Complexity of this loop => M * log(2^N) => M * N */
    for(int i=0; i<query.size(); i++){
        int result = binary_search(sum_arr, 0, sum_arr.size()-1, query[i]);
        res.push_back(result != -1 ? true : false);
    }

    return res;
}

/* Subset sum using bit manipulation*/
vector<bool> subsetSum(vector<int> num, vector<int> query)
{
    vector<bool> res;
    /* Preprocessing of the data */
    bitset<10000> bits;

    bits.reset();

    /* This is done because every set will have an empty subset */
    bits[0]=1;

    
    for(int i=0; i<num.size(); i++){
        /*
        bits << num[i] => This basically sets the bit depicted by num[i]
                          It is so because each element will be present as a subset sum alone.
        bits |  (bits << num[i]) => The idea here is that we need to OR,
                                    current bits with previous so that previous is not lost       
        */
        bits = bits | (bits << num[i]);
    }

    /* Checking subset sum existence for each query */
    for(int i=0; i<query.size(); i++){
        res.push_back(bits[query[i]] ? true : false);
    }

    return res;
}

int main(){

    vector<int> num = {1,2,3};
    vector<int> query = {5,3,8};

    vector<bool> res = subsetSum(num,query);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}