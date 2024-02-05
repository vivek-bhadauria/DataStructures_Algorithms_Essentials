#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Product
{
    char id;
    string name;
    int price;

public:
    Product()
    {
    }

    Product(string name, int price)
    {
        id = name[0];
        this->name = name;
        this->price = price;
    }

    char getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    int getPrice()
    {
        return price;
    }

    void show()
    {
        cout << name << " : Rs " << price << endl;
    }
};

class Item
{
    Product product;
    int quantity;

public:
    Item()
    {
    }

    Item(Product p, int q) : quantity(q), product(p)
    {
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    int getQuantity()
    {
        return quantity;
    }

    int getPrice()
    {
        return quantity * product.getPrice();
    }

    void show()
    {
        cout << quantity << " X " << product.getName() << " = Rs " << getPrice() << endl;
    }
};

class Cart
{

    unordered_map<string, Item> items;

    int getTotal()
    {
        int t = 0;
        for (auto pr : items)
        {
            Item itm = pr.second;
            t += itm.getPrice();
        }
        return t;
    }

public:
    void add(Product p, int q)
    {

        if (items.count(p.getName()) == 0)
        {
            Item *itm = new Item(p, q);
            items[p.getName()] = *itm;
        }
        else
        {
            items[p.getName()].setQuantity(items[p.getName()].getQuantity() + q);
        }
        cout << "Added successfully !!!" << endl;
    }

    void show()
    {
        cout << "-------------------------" << endl;
        int total = 0;
        for (auto pr : items)
        {
            pr.second.show();
            total += pr.second.getPrice();
        }
        if (items.size() > 0)
        {
            cout << "Total : " << total << endl;
            cout << "-------------------------" << endl;
        }
    }

    bool checkout()
    {
        if (items.size() == 0)
        {
            cout << "No items were added to cart !!!";
            return false;
        }

        int total = getTotal();
        int paid = 0;
        cout << "Payment please :" << endl;
        cin >> paid;
        int bal = paid - total;

        if (bal > 0)
        {
            cout << "Change = Rs. " << bal << endl;
            cout << "Thank you !!!" << endl;
            return true;
        }
        cout << "Full payment required !!!" << endl;
        return false;
    }
};

void showInventory(unordered_map<int, Product> inventory)
{
    cout << "Available Products : " << endl;
    for (auto p : inventory)
    {
        char ch = p.first;
        cout << "(" << ch << ") ";
        p.second.show();
    }
}

void processAddToCartChoice(unordered_map<int, Product> &inventory, Cart &cart)
{
    char productChoice;
    int q;
    showInventory(inventory);
    cout << "Enter Product Choice : ";
    cin >> productChoice;
    auto itr = inventory.find(productChoice);
    if (itr == inventory.end())
    {
        cout << "No such product !!!" << endl;
    }
    else
    {
        cout << "Enter quantity : ";
        cin >> q;
        if (q > 0)
        {
            cart.add(itr->second, q);
        }
        else
        {
            cout << "Not a valid quantity !!!" << endl;
        }
    }
}

int main()
{

    unordered_map<int, Product> inventory;
    Cart cart;
    vector<string> products = {"apple", "mango", "guava", "orange"};
    vector<int> prices = {26, 150, 48, 54};

    /* prepare inventory */
    for (int i = 0; i < products.size(); i++)
    {
        Product *p = new Product(products[i], prices[i]);
        inventory.insert(make_pair(p->getId(), *p));
    }

    char choice = 'X';
    while (choice != 'C')
    {
        cout << "Select : " << endl;
        cout << "A. Add to cart" << endl;
        cout << "B. View cart" << endl;
        cout << "C. Checkout cart" << endl;
        cin >> choice;

        if (choice == 'A')
        {
            processAddToCartChoice(inventory, cart);
        }
        else if (choice == 'B')
        {
            cout << "Here is your cart" << endl;
            cart.show();
        }
        else if (choice == 'C')
        {
            cart.show();

            if (!cart.checkout())
            {
                choice = 'X';
            };
        }
    }
}