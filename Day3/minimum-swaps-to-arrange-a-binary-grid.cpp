#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int cntZero[201] = {0}, res = 0;
        bool isNotValid = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j > 0; j--)
            {
                if (grid[i][j] == 1)
                    break;
                cntZero[i] += (grid[i][j] == 0);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (cntZero[i] < n - 1 - i)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (cntZero[j] >= n - 1 - i)
                    {
                        for (int k = j; k >= i + 1; k--)
                        {
                            res++;
                            swap(cntZero[k], cntZero[k - 1]);
                        }
                        break;
                    }
                    if (j == n - 1)
                        isNotValid = true;
                }
            }
        }
        return isNotValid ? -1 : res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
    cout << sol.minSwaps(grid) << endl;
}