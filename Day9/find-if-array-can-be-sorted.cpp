#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        int curBits = 0;
        vector<vector<int>> vec;
        vector<int> segment;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0, j = nums[i];
            while (j)
            {
                cnt += (j % 2 == 1);
                j >>= 1;
            }

            if (curBits == cnt)
            {
                segment.push_back(nums[i]);
            }
            else
            {
                curBits = cnt;
                vec.push_back(segment);
                segment.clear();
                segment.push_back(nums[i]);
            }
        }
        if (!segment.empty())
            vec.push_back(segment);

        int maxVal = -1e9;
        for (auto seg : vec)
        {
            int minVal = 1e9;
            int curMaxVal = -1e9;
            for (auto item : seg)
            {
                minVal = min(minVal, item);
                curMaxVal = max(curMaxVal, item);
            }
            if (maxVal >= minVal)
                return false;
            maxVal = curMaxVal;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << sol.canSortArray(nums);
}