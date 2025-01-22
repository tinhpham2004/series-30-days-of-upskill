#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        int n = nums.size();

        if (n < 2)
            return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != i + 1)
            {
                return false;
            }
        }

        if (nums[n - 2] == nums[n - 1])
            return true;
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    cout << sol.isGood(nums);
}