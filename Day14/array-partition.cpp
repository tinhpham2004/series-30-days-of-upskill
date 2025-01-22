#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < n; i += 2)
        {
            res += nums[i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 4, 3, 2};
    cout << sol.arrayPairSum(nums);
}