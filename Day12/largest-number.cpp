#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b)
             {
                 string strA = to_string(a);
                 string strB = to_string(b);
                 return strA + strB > strB + strA; });

        string res;
        for (int num : nums)
        {
            res += to_string(num);
        }
        if (res[0] == '0')
            return "0";
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    string res = sol.largestNumber(nums);
    cout << res;
}