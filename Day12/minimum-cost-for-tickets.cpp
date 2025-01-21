#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        const int MAX_DAYS = 365;

        unordered_set<int> travelDays(days.begin(), days.end());

        vector<int> dp(MAX_DAYS + 1, 0);

        for (int i = 1; i <= MAX_DAYS; ++i)
        {
            if (travelDays.find(i) == travelDays.end())
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = min({dp[i - 1] + costs[0],
                             dp[max(0, i - 7)] + costs[1],
                             dp[max(0, i - 30)] + costs[2]});
            }
        }

        return dp[MAX_DAYS];
    }
};

int main()
{
    Solution sol;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    int res = sol.mincostTickets(days, costs);
    cout << res;
}