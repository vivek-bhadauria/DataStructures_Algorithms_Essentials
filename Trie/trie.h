#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    bool isTerminal;
    unordered_map<char, Node *> map;

    Node(char data)
    {
        this->data = data;
        this->isTerminal = false;
    }
};

class Trie
{

    Node *root = new Node(NULL);

    void prepareStringStartingFrom(Node *node, string str, vector<string> &res)
    {

        if (node == NULL)
        {
            return;
        }
        Node *curr = node;
        if (curr->isTerminal)
        {
            str.push_back(node->data);
            res.push_back(str);
        }

        for (auto it = curr->map.begin(); it != curr->map.end(); it++)
        {
            if (!curr->isTerminal)
            {
                str.push_back(curr->data);
            }
            prepareStringStartingFrom(it->second, str, res);
            if (!curr->isTerminal)
            {
                str.pop_back();
            }
        }
    }

    Node *findEndOfPrefix(string prefix)
    {
        Node *curr = root;
        string tracedPrefix;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (curr->map[prefix[i]] == NULL)
            {
                return NULL;
            }
            curr = curr->map[prefix[i]];
            tracedPrefix.push_back(curr->data);
        }
        cout << "Traced Prefix : " << tracedPrefix << endl;
        return curr;
    }

public:
    void insert(string str)
    {
        int len = str.length();
        Node *curr = root;
        for (int i = 0; i < len; i++)
        {

            /* if current char is not already present,
            then create a new node with that data and store it the current node's map*/
            if (curr->map[str[i]] == NULL)
            {
                curr->map[str[i]] = new Node(str[i]);
            }
            curr = curr->map[str[i]];
        }
        curr->isTerminal = true;
    }

    bool search(string str)
    {
        int len = str.length();
        Node *curr = root;
        bool found = true;
        for (int i = 0; i < len; i++)
        {
            if (curr->map[str[i]] == NULL)
            {
                return false;
            }
            curr = curr->map[str[i]];
        }
        return curr->isTerminal;
    }

    vector<string> findAll()
    {
        Node *curr = root;
        vector<string> v;
        for (auto it = curr->map.begin(); it != curr->map.end(); ++it)
        {
            prepareStringStartingFrom(it->second, "", v);
        }
        return v;
    }

    vector<string> findAllWithPrefix(string prefix)
    {
        vector<string> res;
        Node *curr = findEndOfPrefix(prefix);
        if (curr == NULL)
        {
            return res;
        }
        if (curr->isTerminal)
        {
            res.push_back(prefix);
        }
        for (auto it = curr->map.begin(); it != curr->map.end(); ++it)
        {
            prepareStringStartingFrom(it->second, prefix, res);
        }
        return res;
    }
};