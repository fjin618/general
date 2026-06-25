// Example program
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void sortArray(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]);
        }
    }
}

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1, 0};
    for (auto x : nums) cout << x << endl;
    sortArray(nums);
    cout << "---------------------------------------------" << endl;
    for (auto x : nums) cout << x << endl;
    
    cout << "---------------------------------------------" << endl;
    
    vector<int> nums2 = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    for (auto x : nums2) cout << x << endl;
    sortArray(nums2);
    cout << "---------------------------------------------" << endl;
    for (auto x : nums2) cout << x << endl;    
    return 0;
}

