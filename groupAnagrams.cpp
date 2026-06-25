// Example program
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> groupAnagrams(const vector<string>& vs)
{
    unordered_map<string, vector<string>> res;
    for (auto s : vs)
    {
        string key = s;
        sort(key.begin(), key.end());
        res[key].push_back(s);
    }
    
    for (auto [key, value] : res)
    {
        cout << "The key: " << key << endl;
        for(auto x : value)
        {
            cout << x << endl;
        }
    }
    
    return res;
}

int main()
{
    vector<string> vs = {"abc", "acb", "bac", "bca", "cab", "cba", "add", "dad"};
    groupAnagrams(vs);
    return 0;
}
