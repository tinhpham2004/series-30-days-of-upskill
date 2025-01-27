#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + matrix[i][j];
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
            }
        }

        int res = 1e9;
        for (int i = 0; i < n; i++)
            res = min(res, dp[n - 1][i]);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << sol.minFallingPathSum(matrix) << endl;
    return 0;
}