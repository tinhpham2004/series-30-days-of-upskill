#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        int n = words.size();
        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }

        string res = "";
        for (int i = 0; i < n; i++)
        {
            bool isValid = true;
            for (int j = words[i].size() - 1; j >= 0; j--)
            {
                string prevWord = words[i].substr(0, j);
                if (prevWord == "")
                    continue;
                if (mp[prevWord] == 0)
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
            {
                if ((res.size() == words[i].size() && res > words[i]) || res.size() < words[i].size())
                    res = words[i];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    cout << sol.longestWord(words);
    return 0;
}