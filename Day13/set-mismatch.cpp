#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {

        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 2)
                res.push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 4};
    vector<int> res = sol.findErrorNums(nums);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}