#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n; i += 3)
        {
            if ((nums[i + 1] - nums[i]) > k || (nums[i + 2] - nums[i + 1]) > k || (nums[i + 2] - nums[i]) > k)
            {
                return {};
            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; i += 3)
        {
            vector<int> temp;
            for (int j = 0; j < 3; j++)
                temp.push_back(nums[i + j]);
            res.push_back(temp);
        }

        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {2, 4, 2, 2, 5, 2};
    int k = 2;
    vector<vector<int>> result = obj.divideArray(nums, k);
    for (auto arr : result)
    {
        for (int num : arr)
        {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}