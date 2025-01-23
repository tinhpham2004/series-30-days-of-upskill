#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();

        map<string, int> cnt;
        for (int i = 0; i < n; i++)
        {
            cnt[words[i]]++;
        }

        sort(words.begin(), words.end(), [this](string a, string b)
             { return a.size() < b.size(); });

        map<string, int> dp;

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            dp[word] = 1;
            for (int j = 0; j < word.size(); j++)
            {
                string childWord = word.substr(0, j) + word.substr(j + 1, word.size());

                if (cnt[childWord] > 0)
                {
                    dp[word] = max(dp[word], dp[childWord] + 1);
                }
            }

            res = max(res, dp[word]);
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << sol.longestStrChain(words);

    return 0;
}