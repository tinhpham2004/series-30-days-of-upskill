#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> zigzagTraversal(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result;
        for (int i = 0; i < m; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < n; j += 2)
                {
                    result.push_back(grid[i][j]);
                }
            }
            else
            {
                for (int j = n - 1 - (n % 2 == 1); j >= 1; j -= 2)
                {
                    result.push_back(grid[i][j]);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{2, 1}, {2, 1}, {2, 1}};
    vector<int> result = sol.zigzagTraversal(grid);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}