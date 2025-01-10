#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> prevSmaller(n, -1), nextSmaller(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prevSmaller[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            int left = prevSmaller[i] + 1;
            int right = nextSmaller[i] - 1;
            long long sum = prefixSum[right + 1] - prefixSum[left];
            res = max(res, nums[i] * sum);
        }

        return res % MOD;
    }
};

int main()
{
    vector<int> nums = {2, 2};
    Solution sol;
    cout << sol.maxSumMinProduct(nums) << endl;
}
