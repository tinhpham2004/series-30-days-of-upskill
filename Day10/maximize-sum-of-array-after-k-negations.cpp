#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0 && k > 0)
            {
                k--;
                nums[i] *= -1;
            }
        }

        sort(nums.begin(), nums.end());

        int sum = 0;

        if (k > 0 && k % 2 == 1)
        {
            nums[0] *= -1;
        }

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 2, 3};
    int k = 1;
    int res = sol.largestSumAfterKNegations(nums, k);

    cout << res;
}