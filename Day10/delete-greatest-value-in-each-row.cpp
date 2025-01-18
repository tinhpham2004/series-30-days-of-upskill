#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // sort increasingly
        for (int i = 0; i < m; i++)
        {
            sort(grid[i].begin(), grid[i].end());
        }

        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int maxVal = -1e9;
            for (int j = m - 1; j >= 0; j--)
            {
                maxVal = max(maxVal, grid[j][i]);
            }
            res += maxVal;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 4}, {3, 3, 1}};
    cout<<sol.deleteGreatestValue(grid);
}