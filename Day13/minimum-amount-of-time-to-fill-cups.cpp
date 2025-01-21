#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        sort(amount.begin(), amount.end());

        if (amount[0] + amount[1] < amount[2])
            return amount[2];

        return ((amount[0] + amount[1] - amount[2]) / 2 + (amount[0] + amount[1] - amount[2]) % 2) + amount[2];
    }
};

int main()
{
    Solution sol;
    vector<int> amount = {1, 4, 2};
    int res = sol.fillCups(amount);
    cout << res;
}