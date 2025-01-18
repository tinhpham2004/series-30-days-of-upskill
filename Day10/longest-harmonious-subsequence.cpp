#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxVal = 0, res = 0, minValId = 0;
        for (int i = 1; i < n; i++)
        {
            while (nums[i] - nums[minValId] > 1)
                minValId++;
            if (nums[i] - nums[minValId] == 1)
            {
                maxVal = i - minValId + 1;
            }
            res = max(res, maxVal);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << sol.findLHS(nums);
}