#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), cntSame = 0;
        long long res = 0;
        vector<int> cnt(1e5 + 1, 0);
        vector<long long> sum(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }

        for (int i = 0; i < k; i++)
        {
            cnt[nums[i]]++;
            if (cnt[nums[i]] >= 2)
            {
                cntSame++;
            }
        }

        if (cntSame == 0)
        {
            res = max(res, sum[k] - sum[0]);
        }

        for (int i = k; i < n; i++)
        {
            if (cnt[nums[i - k]] >= 2)
            {
                cntSame--;
            }
            cnt[nums[i - k]]--;
            cnt[nums[i]]++;
            if (cnt[nums[i]] >= 2)
            {
                cntSame++;
            }
            if (cntSame == 0)
            {
                res = max(res, sum[i + 1] - sum[i + 1 - k]);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    cout << sol.maximumSubarraySum(nums, k);
}