#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        long long curCost = 0;
        int res = 0;

        for (int right = 0; right < n; ++right)
        {
            if (right > 0)
            {
                curCost += (long long)(nums[right] - nums[right - 1]) * (right - left);
            }

            while (curCost > k)
            {
                curCost -= nums[right] - nums[left];
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 4};
    int k = 5;
    cout << sol.maxFrequency(nums, k);
}