#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        int n = startWords.size();
        int m = targetWords.size();
        unordered_map<string, int> startWordsContains;

        for (int i = 0; i < n; i++)
            sort(startWords[i].begin(), startWords[i].end());

        for (int i = 0; i < m; i++)
            sort(targetWords[i].begin(), targetWords[i].end());

        for (int i = 0; i < n; i++)
        {
            startWordsContains[startWords[i]]++;
        }

        int res = 0;
        for (int i = 0; i < m; i++)
        {
            bool isExist = false;
            for (int j = 0; j < targetWords[i].size(); j++)
            {
                string newStrLeft = targetWords[i].substr(0, j);
                string newStrRight = targetWords[i].substr(j + 1, targetWords[i].size());
                string newStr = newStrLeft + newStrRight;
                if (startWordsContains[newStr] > 0)
                    isExist = true;
            }
            res += isExist;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> startWords = {"ant", "act", "tack"};
    vector<string> targetWords = {"tack", "act", "acti"};
    int res = sol.wordCount(startWords, targetWords);
    cout << res;
}