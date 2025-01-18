#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr;
        for (int i = 0; i < n; i++)
            arr.push_back(nums[i]);

        sort(arr.begin(), arr.end());


        vector<int> res;

        for (int index = 0; index < n; index++)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == nums[index])
                {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {8, 1, 2, 2, 3};

    vector<int> res = sol.smallerNumbersThanCurrent(nums);

    for (auto item : res)
    {
        cout << item << ' ';
    }
}