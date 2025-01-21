#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(), nums.end());

        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            int maxLen = 0;
            int sum = 0;

            for (int j = 0; j < n; j++)
            {
                sum += nums[j];
                if (sum > queries[i])
                {
                    res.push_back(j);
                    break;
                }

                if (j == n - 1)
                {
                    res.push_back(n);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 2, 1};
    vector<int> queries = {3, 10, 21};
    vector<int> res = sol.answerQueries(nums, queries);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}