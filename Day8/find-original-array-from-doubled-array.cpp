#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2)
        {
            return {};
        }

        sort(changed.begin(), changed.end());

        int cnt[200002];

        cnt[0] = 0;

        for (int i = 0; i < n; i++)
        {
            cnt[changed[i]] = 0;
            cnt[changed[i] * 2] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            cnt[changed[i]]++;
        }

        vector<int> res;

        if (cnt[0] % 2)
        {
            return {};
        }
        for (int i = 0; i < n; i++)
        {
            if (cnt[changed[i]] >= 1 && cnt[2 * changed[i]] >= 1)
            {
                res.push_back(changed[i]);
                cnt[changed[i]]--;
                cnt[changed[i] * 2]--;
            }
        }
        for (auto num : res)
        {
            cout << num << ' ';
        }
        return res.size() == n / 2 ? res : vector<int>();
    }
};

int main()
{
    Solution obj;
    vector<int> changed = {4, 4, 16, 20, 8, 8, 2, 10};
    vector<int> result = obj.findOriginalArray(changed);
    for (auto num : result)
    {
        cout << num << ' ';
    }
    return 0;
}