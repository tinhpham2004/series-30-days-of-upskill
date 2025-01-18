#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int n = ages.size();
        int totalAges = 0;
        vector<int> cnt(121, 0);

        for (int i = 0; i < n; i++)
        {
            cnt[ages[i]]++;
            cout << ages[i] << ' ' << cnt[ages[i]] << '\n';
        }

        for (int x = 1; x < 121; x++)
        {
            for (int y = 1; y < 121; y++)
            {
                if ((y <= 0.5 * x + 7) || (y > x) || (y > 100 && x < 100))
                    continue;
                if (x == y)
                    totalAges += cnt[x] * (cnt[x] - 1);
                else
                    totalAges += cnt[x] * cnt[y];
            }
        }

        return totalAges;
    }
};

int main()
{
    Solution sol;
    vector<int> ages = {20, 30, 100, 110, 120};
    cout << sol.numFriendRequests(ages);
}