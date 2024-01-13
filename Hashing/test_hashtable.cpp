#include <iostream>
#include <string>
#include "hashtable.h"
using namespace std;

int main()
{

    Hashtable<int> h;

    h.insert("Banana", 100);
    h.insert("Guava", 200);
    h.insert("Apple", 300);
    h.insert("Pear", 400);
    h.insert("Pineapple", 500);
    h.insert("Grapes", 600);

    h.print();
    char ans = 'Y';
    while (ans == 'Y' || ans == 'y')
    {
        string fruit;
        cout << "Enter fruit name : " << endl;
        cin >> fruit;
        int *price = h.search(fruit);
        int price_val = price != NULL ? *price : -1;
        cout << "Value of " << fruit << " - " << price_val << endl;
        cout << "Want to contiue (Y or N)? " << endl;
        cin >> ans;
    };

    h.erase("Apple");
    h.erase("Guava");
    h.erase("Pear");
    h.erase("Kiwi");

    h.print();
    
    h["Litchi"] = 800;
    cout<<"Cost of Litchi : "<<h["Litchi"]<<endl;
    h["Litchi"] = h["Litchi"] + 40;
    cout<<"Updated Cost of Litchi : "<<h["Litchi"]<<endl;

    h.print();
}