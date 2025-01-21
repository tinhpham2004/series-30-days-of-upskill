#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        sort(rides.begin(), rides.end(), [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });

        vector<long long> dp(n + 1, 0);

        int rideIndex = 0;

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];

            while (rideIndex < rides.size() && rides[rideIndex][1] == i)
            {
                int start = rides[rideIndex][0];
                int end = rides[rideIndex][1];
                int tip = rides[rideIndex][2];
                dp[i] = max(dp[i], dp[start] + (end - start + tip));
                rideIndex++;
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution sol;
    int n = 5;
    vector<vector<int>> rides = {{2, 5, 4}, {1, 5, 1}};
    cout << sol.maxTaxiEarnings(n, rides);
}