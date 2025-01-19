#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        vector<int> evenVec, oddVec;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
                oddVec.push_back(nums[i]);
            else
                evenVec.push_back(nums[i]);
        }

        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                res.push_back(oddVec.back());
                oddVec.pop_back();
            }
            else
            {
                res.push_back(evenVec.back());
                evenVec.pop_back();
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 2, 5, 7};
    vector<int> res = sol.sortArrayByParityII(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}