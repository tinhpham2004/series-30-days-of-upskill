#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();
        // sort arr1
        sort(arr1.begin(), arr1.end());
        vector<int> res;
        // loop arr2, element => (e in arr 1 => element == e) then push_back resLeft
        //                                   => element != e then push_back resRight
        // res = resLeft + resRight;

        for (auto item2 : arr2)
        {
            for (auto item1 : arr1)
            {
                if (item2 == item1)
                    res.push_back(item1);
            }
        }

        for (auto item1 : arr1)
        {
            bool isExist = false;
            for (auto item2 : arr2)
            {
                if (item2 == item1)
                    isExist = true;
            }
            if (!isExist)
                res.push_back(item1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> res = sol.relativeSortArray(arr1, arr2);
    for (auto item : res)
    {
        cout << item << ' ';
    }
}