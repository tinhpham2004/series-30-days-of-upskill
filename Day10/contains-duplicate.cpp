#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            mp[nums[i]]++;

        for (auto item : mp)
        {
            if (item.second >= 2)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2};
    cout << sol.containsDuplicate(nums);
}