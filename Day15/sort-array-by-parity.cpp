#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        deque<int> dq;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
                dq.push_back(nums[i]);
            else
                dq.push_front(nums[i]);
        }

        vector<int> res(dq.begin(), dq.end());
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 2, 4};
    vector<int> result = sol.sortArrayByParity(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}