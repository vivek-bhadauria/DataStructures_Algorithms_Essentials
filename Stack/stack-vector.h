#include<vector>
using namespace std;

template<typename T>
class Stack{

    vector<T> v;

    public:

    void push(T data){
        v.push_back(data);
    }

    void pop(){
        v.pop_back();
    }

    T top(){
        return v.back();
    }

    bool empty(){
        return v.empty();
    }
};