#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;
        unordered_map<int, int> mp;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            mp[sum]++;
            left++;
            right--;
        }

        return mp.size();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 2, 3};
    cout << sol.distinctAverages(nums);
}