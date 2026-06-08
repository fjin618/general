#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<utility>
#include<queue>
#include<list>

using namespace std;

template<typename T>
void verify_answer(const T& answer, const T& expected)
{
    if (answer == expected)
    {
        cout << "Test passed" << endl;
    }
    else
    {
        cout << "Test failed" << endl;
        //cout << "Answer: " << answer << endl;
        //cout << "Expected: " << expected << endl;
    }
}

vector<int> twoSum(const vector<int>& nums, int target)
{
    unordered_map<int, int> pastNums;
    for(int i = 0;  i < nums.size(); ++i)
    {
        auto need = target - nums[i];
        if (pastNums.count(need))
        {
            return {pastNums[need], i};
        }
        pastNums[nums[i]] = i;
    }
    return {};
}

vector<int> mExceptSelf(const vector<int>& nums)
{
    auto n = nums.size();
    vector<int> res(n, 1);
    int left = 1;
    int right = 1;
    for(int i = 0; i < n; ++i)
    {
        res[i] = left;
        left *= nums[i];
    }
    for(int i = n - 1; i >= 0; --i)
    {
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}

int maxSubArray(const vector<int>& nums)
{
    int maxSum = nums[0];
    int currentSum = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

vector<int> topKFrequent(const vector<int>& nums, int k)
{
    unordered_map<int, int> freq;
    for(int num : nums) ++freq[num];
    for(auto [num, freq] : freq)
    {
        cout << num << " " << freq << endl;
    }
    cout << "--------------------------------" << endl;
    priority_queue<pair<int, int>> pq;
    for(auto [num, freq] : freq)
    {
        pq.push({freq, num});
    }
    vector<int> res;
    while(k-- && !pq.empty())
    {
        cout << pq.top().second << " " << pq.top().first << endl;
        res.push_back(pq.top().second);
        pq.pop();
    }
    cout << "--------------------------------" << endl;
    return res;
}

int longestSubSring(const string& s)
{
    vector<char> last_postion(128, -1);
    int left = 0;
    int max_len = 0;
    for (int right = 0; right < s.length(); ++right)
    {
        char ch = s[right];
        if (last_postion[ch] >= left)
        {
            left = last_postion[ch] + 1;
        }
        last_postion[ch] = right;
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}

void reverseString(string& s)
{
    int start = 0, end = s.length() - 1;
    while (start < end) swap(s[start++], s[end--]);
}

void reverseString_v2(string& s)
{
    string t = s;
    for (int start = 0, end = s.length() - 1; start < s.length(); start++, end--)
    {
        s[start] = t[end];
    }
}

unordered_map<string, vector<string>> groupAnagrams(const vector<string>& vs)
{
    // vector<string> vs = {"abc", "acb", "bac", "bca", "cab", "cba", "add", "dad"};
    unordered_map<string, vector<string>> res;
    for (auto s : vs)
    {
        string key = s;
        sort(key.begin(), key.end());
        res[key].push_back(s);
    }

    for (auto& [key, value] : res)
    {
        cout << "Key " << key << endl;
        for (auto v : value)
        {
            cout << v << endl;
        }
    }
    return res;
}

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(const vector<int>& nums)
{
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    for (int num : nums)
    {
        ListNode* newNode = new ListNode(num);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            curr->next = newNode;
        }
        curr = newNode;
    }
    return head;
}

ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode dummy(0);
    ListNode* p = &dummy;
    while(list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            p->next = list1;
            list1 = list1->next;
        }
        else
        {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    p->next = list1 ? list1 : list2;
    return dummy.next;
}

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key)
    {
        if (!map.count(key)) return -1;
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.emplace_front(key, value);
        map[key] = cache.begin();
        return value;
    }

    void put(int key, int value)
    {
        if (map.count(key))
        {
            auto it = map[key];
            cache.erase(it);
        }
        else
        {
            if (cache.size() >= capacity)
            {
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }

    void printCache()
    {
        for (auto& [key, value] : cache)
        {
            cout << key << " " << value << endl;
        }
    }
};

vector<int> spiralOrder(const vector<vector<int>>& matrix)
{
    vector<int> res;
    int top = 0;
    int buttom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() -1;
    while(true)
    {
        // top
        for(int i = left; i <=right; i++) res.push_back(matrix[top][i]);
        if (++top > buttom) break;

        // right
        for (int i = top; i <= buttom; i++) res.push_back(matrix[i][right]);
        if (--right < left) break;

        // buttom
        for (int i = right; i >= left; i--) res.push_back(matrix[buttom][i]);
        if(--buttom < top) break;

        // left
        for (int i = buttom; i >= top; i--) res.push_back(matrix[i][left]);
        if (++left > right) break;
    }
    return res;
}

int climbStairs_v1(int n)
{
    if (n <= 2) return n;
    return climbStairs_v1(n - 1) + climbStairs_v1(n - 2);
}

int climbStairs_v2(int n)
{
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int climbStairs_v3(int n)
{
    if (n <= 2) return n;
    int step_1 = 1;
    int step_2 = 2;
    int total_steps = 0;
    for (int i = 3; i <= n; i++)
    {
        total_steps = step_1 + step_2;
        step_1 = step_2;
        step_2 = total_steps;
    }
    return total_steps;
}

bool isPalindrome(int x)
{
    if (x < 0 or (x % 10 == 0 and x!= 0)) return false;
    int rev_num = 0;
    while (x > rev_num)
    {
        rev_num = rev_num * 10 + x % 10;
        x /= 10;
    }
    if (x == rev_num or x == rev_num / 10) return true;
    return false;
}

vector<int> sortArray(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
        }
    }
    return nums;
}

int main(int argc, char** argv)
{
    vector<int> nums = {5, 2, 3, 1, 4};
    verify_answer(sortArray(nums), {1, 2, 3, 4, 5});
    return 0;
}