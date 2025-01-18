#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        int n = target.size();
        unordered_map<int, int> mpTarget, mpArr;

        for (int i = 0; i < n; i++)
        {
            mpTarget[target[i]]++;
            mpArr[arr[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mpTarget[target[i]] != mpArr[target[i]])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> target = {1, 2, 3, 4};
    vector<int> arr = {2, 4, 1, 3};
    bool res = sol.canBeEqual(target, arr);
    cout << res;
}