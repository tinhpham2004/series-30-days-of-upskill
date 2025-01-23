#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[digits[i]]++;
        }

        vector<int> res;
        for (int i = 100; i <= 999; i++)
        {
            int firstDigit = i / 100;
            int secondDigit = (i / 10) % 10;
            int thirdDigit = i % 10;

            if (thirdDigit % 2)
                continue;

            if (mp[firstDigit] > 0)
            {
                mp[firstDigit]--;
            }
            else
            {
                continue;
            }

            if (mp[secondDigit] > 0)
            {
                mp[secondDigit]--;
            }
            else
            {
                mp[firstDigit]++;
                continue;
            }

            if (mp[thirdDigit] > 0)
            {
                mp[thirdDigit]--;
            }
            else
            {
                mp[firstDigit]++;
                mp[secondDigit]++;
                continue;
            }

            res.push_back(i);
            mp[firstDigit]++;
            mp[secondDigit]++;
            mp[thirdDigit]++;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> digits = {2, 1, 3, 0};
    vector<int> res = sol.findEvenNumbers(digits);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}