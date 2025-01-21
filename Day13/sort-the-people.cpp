#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct PeopleInfor
    {
        string name;
        int height;
    };

    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        vector<PeopleInfor> vec;

        for (int i = 0; i < n; i++)
        {
            vec.push_back({names[i], heights[i]});
        }

        sort(vec.begin(), vec.end(), [this](PeopleInfor a, PeopleInfor b)
             { return a.height > b.height; });

        vector<string> res;

        for (int i = 0; i < n; i++)
            res.push_back(vec[i].name);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> names = {"Alex", "Charlie", "Michael"};
    vector<int> heights = {1, 2, 3};
    vector<string> res = sol.sortPeople(names, heights);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}