#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        sort(special.begin(), special.end());
        int res = 0;
        res = max(special[0] - bottom, top - special[special.size() - 1]);
        for (int i = 1; i < special.size(); i++)
        {
            res = max(res, special[i] - special[i - 1] - 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int bottom = 28;
    int top = 50;
    vector<int> special = {35, 48};
    cout << sol.maxConsecutive(bottom, top, special);
}
