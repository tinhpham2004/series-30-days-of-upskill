#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int cnt = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                cnt++;
                if (cnt == 3)
                {
                    return nums[i];
                }
            }
        }

        return nums[n - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 1};
    cout << sol.thirdMax(nums);
}