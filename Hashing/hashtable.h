#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;
    Node(string key, T value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
};

template <typename T>
class Hashtable
{
    Node<T> **table;
    int cs;
    int ts;
    float load_factor = 0.7;

    int hash(string key)
    {

        int idx = 0;
        int power = 29;
        for (int i = 0; i < key.size(); i++)
        {
            idx = idx % ts  + (key.at(i) * power) % ts;
            power = (power * power) % ts;
        }

        return idx % ts;
    }

    void delete_list(Node<T> *node)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->next != NULL)
        {
            delete_list(node->next);
        }
        delete node;
    }

    void rehash()
    {
        /* Create pointers to old table */
        Node<T> **old_table = table;
        int old_table_ts = ts;

        /* Make a new table with double the orginal size such that table variable points to new table */
        cs = 0;
        ts = old_table_ts * 2 + 1;
        table = new Node<T> *[ts];

        /* initialize new table buckets to null */
        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }

        /* Copy elements from old table to new table */
        for (int i = 0; i < old_table_ts; i++)
        {
            Node<T> *temp = old_table[i];

            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            /* delete complete linked list at oldtable[i] */
            delete_list(old_table[i]);
        }

        /* delete old table */
        delete[] old_table;
    }

public:
    Hashtable(int default_size = 7)
    {
        ts = default_size;
        table = new Node<T> *[ts];
        cs = 0;

        for (int i = 0; i < ts; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {

        int idx = hash(key);
        Node<T> *node = new Node<T>(key, value);

        node->next = table[idx];
        table[idx] = node;
        cs++;

        float current_load_factor = cs / float(ts);
        if (current_load_factor > load_factor)
        {
            rehash();
        }
    }

    T* search(string key)
    {

        int idx = hash(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key.compare(key) == 0)
            {
                return &temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void erase(string key)
    {
        int idx = hash(key);
        Node<T> *temp = table[idx];
        Node<T> *prev_temp = NULL;
        int found = 0;
        while (temp != NULL)
        {
            if (temp->key.compare(key) == 0)
            {
                found = 1;
                break;
            }
            prev_temp = temp;
            temp = temp->next;
        }
        if (found == 0)
        {
            return;
        }
        else if (temp == table[idx])
        {
            table[idx] = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else if (temp != NULL)
        {
            prev_temp->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    T& operator[](string key){
        T* valueFound = search(key);
        if(valueFound == NULL){
            T obj;
            insert(key, obj);
            valueFound = search(key);
        }
        return *valueFound;
    }

    void print()
    {

        for (int i = 0; i < ts; i++)
        {
            cout << "Bucket " << i << " -- ";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << ":" << temp->value << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};