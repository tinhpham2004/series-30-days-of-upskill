#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.size();
        if (n <= 1)
            return 0;

        // Left and right unique character counts
        unordered_set<char> leftSet, rightSet;
        vector<int> leftCount(n, 0), rightCount(n, 0);

        // Calculate unique character counts for the left prefix
        for (int i = 0; i < n; ++i)
        {
            leftSet.insert(s[i]);
            leftCount[i] = leftSet.size();
        }

        // Calculate unique character counts for the right suffix
        for (int i = n - 1; i >= 0; --i)
        {
            rightSet.insert(s[i]);
            rightCount[i] = rightSet.size();
        }

        // Count valid splits
        int res = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (leftCount[i] == rightCount[i + 1])
            {
                ++res;
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abcd";
    cout << sol.numSplits(s);
}
