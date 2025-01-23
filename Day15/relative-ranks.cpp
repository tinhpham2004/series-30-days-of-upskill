#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();

        vector<int> vec(score.begin(), score.end());

        sort(vec.begin(), vec.end());

        map<int, string> mp;

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                mp[vec[i]] = "Gold Medal";
            }

            if (i == n - 2)
            {
                mp[vec[i]] = "Silver Medal";
            }

            if (i == n - 3)
            {
                mp[vec[i]] = "Bronze Medal";
            }

            if (i < n - 3)
            {
                mp[vec[i]] = to_string(n - i);
            }
        }

        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(mp[score[i]]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> res = sol.findRelativeRanks(score);
    for (string s : res)
    {
        cout << s << " ";
    }
    return 0;
}