#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        if (coins[0][0] < 0)
        {
            dp[0][0][1] = 0;
            dp[0][0][2] = coins[0][0];
        }
        else
        {
            dp[0][0][2] = coins[0][0];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;

                for (int k = 0; k < 3; k++)
                {
                    if (j > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);

                    if (i > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);

                    if (coins[i][j] < 0 && k > 0)
                    {
                        if (j > 0)
                            dp[i][j][k - 1] = max(dp[i][j][k - 1], dp[i][j - 1][k]);
                        if (i > 0)
                            dp[i][j][k - 1] = max(dp[i][j][k - 1], dp[i - 1][j][k]);
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> coins = {
        {-7, 12, 12, 13},
        {-6, 19, 19, -6},
        {9, -2, -10, 16},
        {-4, 14, -10, -9},
    };
    cout << sol.maximumAmount(coins) << endl;
    return 0;
}