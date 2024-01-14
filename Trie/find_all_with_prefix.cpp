#include "trie.h"
#include <algorithm>
#include <vector>

vector<string> findPrefixStrings(vector<string> words, string prefix)
{
    Trie trie;
    cout << "Prefix : " << prefix << endl;
    for (string s : words)
    {
        trie.insert(s);
        cout << s << " ";
    }
    cout << endl;

    vector<string> v = trie.findAllWithPrefix(prefix);
    for (string s : v)
    {
        cout << s << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());

    return v;
}

int main()
{

    vector<string> input = {"abc", "abd", "acde", "abe", "aeb", "abba"};
    findPrefixStrings(input, "ab");
}