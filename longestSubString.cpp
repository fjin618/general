// Example program
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

int longestSubString(const string& s)
{
    vector<int> last_pos(128, -1);
    int left = 0;
    int max_len = 0;
    for (int right = 0; right < s.length(); ++right)
    {
        char ch = s[right];
        if (last_pos[ch] >= left)
        {
            left = last_pos[ch] + 1;
        }
        last_pos[ch] = right;
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

int main()
{
    string s("abcdabcdea");
    cout << longestSubString(s) << endl;
    return 0;
}
