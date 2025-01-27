#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int res = 0;
        for(int j = 0; j < m; j++) {
            int count = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
            res += max(count, n - count) * (1 << (m - j - 1));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << sol.matrixScore(grid) << endl;
    return 0;
}