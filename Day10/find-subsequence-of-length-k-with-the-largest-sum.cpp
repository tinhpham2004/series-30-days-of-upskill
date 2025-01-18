#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Element
    {
        int val;
        int index;
    };

    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        // sum[1001]
        int n = nums.size();
        vector<Element> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end(), [this](Element a, Element b)
             { return a.val < b.val; });
        vector<Element> temp;
        for (int i = n - 1; i > n - 1 - k; i--)
        {
            temp.push_back(vec[i]);
        }

        sort(temp.begin(), temp.end(), [this](Element a, Element b)
             { return a.index < b.index; });

        vector<int> res;
        for (auto item : temp)
        {
            res.push_back(item.val);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1,-2,3,4}; 
    int k = 3;
    vector<int> res = sol.maxSubsequence(nums, k);
    for (auto item : res)
    {
        cout << item << ' ';
    }
}