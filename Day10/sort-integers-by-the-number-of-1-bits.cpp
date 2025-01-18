#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBits(int val)
    {
        int cnt = 0;
        while (val)
        {
            if (val & 1)
                cnt++;
            val >>= 1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), [this](int a, int b)
             { int countBitsA = countBits(a); 
             int countBitsB = countBits(b);
             return (countBitsA < countBitsB) || (countBitsA == countBitsB && a < b); });

        return arr;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> res = sol.sortByBits(arr);

    for (auto item : res)
    {
        cout << item << ' ';
    }
}