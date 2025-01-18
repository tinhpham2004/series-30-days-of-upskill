#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> st;

        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++)
            st.insert(nums[i]);
        for (auto item : st)
        {
            if (item > 0)
                res++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 5, 0, 3, 5};
    cout << sol.minimumOperations(nums);
}