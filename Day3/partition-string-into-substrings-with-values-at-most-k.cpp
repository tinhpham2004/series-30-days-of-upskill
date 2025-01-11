#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPartition(string s, int k)
    {
        long long curNum = 0;
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            int digit = s[i] - '0';
            if (digit > k)
                return -1;

            if (curNum * 10 + digit <= k)
            {
                curNum = curNum * 10 + digit;
            }
            else
            {
                res++;
                curNum = digit;
            }
        }

        return res + 1;
    }
};

int main()
{
    Solution sol;
    string s = "1234";
    int k = 10;
    cout << sol.minimumPartition(s, k) << endl;
}