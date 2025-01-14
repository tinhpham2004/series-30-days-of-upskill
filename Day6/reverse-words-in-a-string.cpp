#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        s += " ";
        int n = s.size();
        vector<string> words;
        int id = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i > 0 && s[i] == ' ' && s[i - 1] == ' ') || (i == 0 && s[i] == ' '))
            {
                id = i + 1;
                continue;
            }
            if (s[i] == ' ')
            {
                words.push_back(s.substr(id, i - id));
                id = i + 1;
            }
        }

        string result;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            result += words[i];
            if (i != 0)
            {
                result += " ";
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "  hello world  ";
    cout << sol.reverseWords(s) << endl;
    return 0;
}