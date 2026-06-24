#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k)
{
    unordered_map<int, int> num_freq;
    for (auto num : nums) ++num_freq[num];
    
    priority_queue<pair<int, int>> pq;
    for (auto [num, freq] : num_freq)
    {
        pq.push({freq, num});
        cout << num << " " << freq << endl;
    }
    
    vector<int> res;
    while(k-- and !pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,2,2,2,3,3,3,3,4,4,4,4,4,4,4,4,4,5};
    auto res = topKFrequent(nums, 5);
    for (auto p : res)
        cout << p << endl;
    return 0;
}
