#include <iostream>
#include "vector.h"
using namespace std;

int main(){

    Vector<int> test(2);

    test.push_back(10);
    cout<<"On push_back(10) Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<endl;
    
    test.push_back(20);
    cout<<"On push_back(20) Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<endl;

    test.push_back(30);
    cout<<"On push_back(30) Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<endl;
    
    for(int i=0; i< test.size(); i++){
        cout<<test.get(i)<<" ";
    }
    cout<<endl;

    cout<<"==== Printing with operator ===="<<endl;
    for(int i=0; i< test.size(); i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;

    test.push_back(40);
    cout<<"On push_back(40) Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<endl;

    test.push_back(50);
    cout<<"On push_back(50) Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<endl;


    for(int i=0; i< test.size(); i++){
        cout<<test.get(i)<<" ";
    }
    cout<<endl;

    int temp = -10;
    temp = test.pop_back();
    cout<<"On 1st pop_back() Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<", removed : "<<temp<<endl;

    temp = test.pop_back();
    cout<<"On 2nd pop_back() Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<", removed : "<<temp<<endl;

    temp = test.pop_back();
    cout<<"On 3rd pop_back() Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<", removed : "<<temp<<endl;


    for(int i=0; i< test.size(); i++){
        cout<<test.get(i)<<" ";
    }
    cout<<endl;
    
    cout<<"Front : "<<test.front()<<endl;
    cout<<"Back : "<< test.back()<<endl;

    temp = test.pop_back();
    cout<<"On 4th pop_back() Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<", removed : "<<temp<<endl;

    temp = test.pop_back();
    cout<<"On 5th pop_back() Size : "<<test.size()<<", Capacity : "<<test.getCapacity()<<", removed : "<<temp<<endl;

    for(int i=0; i< test.size(); i++){
        cout<<test.get(i)<<" ";
    }
    cout<<endl;

    cout<<"Front : "<<test.front()<<endl;
    cout<<"Back : "<< test.back()<<endl;

    Vector<char> vowels;
    
    vowels.push_back('a');
    vowels.push_back('e');
    vowels.push_back('i');
    vowels.push_back('o');
    vowels.push_back('u');

    for(int i=0; i< vowels.size(); i++){
        cout<<vowels[i]<<" ";
    }
    cout<<endl;
}