#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums1.size();
        vector<int> diffCount(100001, 0);
        int totalK = k1 + k2;

        // Calculate the frequency of absolute differences
        for (int i = 0; i < n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            diffCount[diff]++;
        }

        // Reduce the largest differences using the total number of operations (k1 + k2)
        for (int i = 100000; i > 0 && totalK > 0; i--)
        {
            if (diffCount[i] > 0)
            {
                int reduceCount = min(diffCount[i], totalK);
                diffCount[i] -= reduceCount;
                diffCount[i - 1] += reduceCount;
                totalK -= reduceCount;
            }
        }

        // Calculate the sum of squares of the remaining differences
        long long res = 0;
        for (int i = 1; i <= 100000; i++)
        {
            if (diffCount[i] > 0)
            {
                res += 1LL * i * i * diffCount[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 7};
    vector<int> nums2 = {3, 4};
    int k1 = 1, k2 = 1;
    cout << sol.minSumSquareDiff(nums1, nums2, k1, k2);
}