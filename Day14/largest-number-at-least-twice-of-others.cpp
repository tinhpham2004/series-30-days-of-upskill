#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();

        int maxVal = -1e9, maxIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (maxIndex == i)
                continue;

            if (nums[i] * 2 > maxVal)
            {
                maxIndex = -1;
                break;
            }
        }

        return maxIndex;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 6, 1, 0};
    cout << sol.dominantIndex(nums);
}