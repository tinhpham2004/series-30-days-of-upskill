#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        long long res = 0;
        for (int i = n - 1; i > n - 1 - k; i--)
        {
            int curHappiness = (happiness[i] - (n - 1 - i));
            if (curHappiness < 0)
                curHappiness = 0;

            res += curHappiness;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> happiness = {1, 2, 3};
    int k = 2;
}