#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 0)
            return {};

        vector<int> vec(arr.begin(), arr.end());

        sort(vec.begin(), vec.end());

        map<int, int> mp;

        int rank = 1;
        mp[vec[0]] = rank;
        for (int i = 1; i < n; i++)
        {
            if (vec[i] > vec[i - 1])
            {
                mp[vec[i]] = ++rank;
            }
            else
            {
                mp[vec[i]] = rank;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(mp[arr[i]]);
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {40, 10, 20, 30};
    vector<int> res = sol.arrayRankTransform(arr);
    for (auto item : res)
    {
        cout << item << " ";
    }
}