#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        unordered_map<string, int> map;
        vector<string> result;
        for (int i = 0; i < n - 9; i++)
        {
            string sub = s.substr(i, 10);
            map[sub]++;
            if (map[sub] == 2)
            {
                result.push_back(sub);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = sol.findRepeatedDnaSequences(s);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}