#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();    // number of lines
        int m = nums[0].size(); // number of columns

        unordered_map<int, int> mp;

        for (auto vec : nums)
        {
            for (auto item : vec)
            {
                mp[item]++;
            }
        }

        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            if (mp[nums[0][i]] == n)
                res.push_back(nums[0][i]);
        }

        sort(res.begin(), res.end());

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> nums = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    vector<int> res = sol.intersection(nums);
    for (auto item : res)
    {
        cout << item << " ";
    }
}