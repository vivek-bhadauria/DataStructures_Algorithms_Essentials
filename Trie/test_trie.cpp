#include <vector>
#include "trie.h"
using namespace std;

int main()
{

    vector<string> input = {"apple", "banana", "guava", "orange", "avocado", "app"};
    vector<string> query = {"apples", "banana", "mango", "guava", "apple"};
    Trie trie;

    for (string str : input)
    {
        trie.insert(str);
    }

    for (string str : query)
    {
        string res = trie.search(str) ? "YES" : "NO";
        cout << res << ", ";
    }
    cout << endl;

    vector<string> input2 = {"abc", "abd", "acde", "abe", "aeb", "abba", "abdc", "ab"};
    Trie trie2;
    for (string s : input2)
    {
        trie2.insert(s);
    }

    vector<string> result = trie2.findAll();
    for (string x : result)
    {
        cout << x << ", ";
    }
    cout << endl;

    vector<string> v = trie2.findAllWithPrefix("ab");
    for (string s : v)
    {
        cout << s << ", ";
    }
    cout << endl;
}