// Example program
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

void reverseString(string& s)
{
    int i = 0;
    int j = s.length() - 1;
    while(i < j) swap(s[i++], s[j--]);
}

int main()
{
    string s("abcdefghijk");
    cout << s << endl;
    reverseString(s);
    cout << s << endl;
    return 0;
}
