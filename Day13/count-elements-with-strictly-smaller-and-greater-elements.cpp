#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &nums)
    {

        int n = nums.size();

        if (n <= 2)
            return 0;

        sort(nums.begin(), nums.end());

        int minIndex = 0;
        while (minIndex < n && nums[minIndex] == nums[0])
        {
            minIndex++;
        }

        int maxIndex = n - 1;
        while (maxIndex >= 0 && nums[maxIndex] == nums[n - 1])
        {
            maxIndex--;
        }

        return max(maxIndex - minIndex + 1, 0);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-3, 3, 3, 90};
    cout << sol.countElements(nums);
}