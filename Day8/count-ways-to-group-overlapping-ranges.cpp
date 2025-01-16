#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Interval
    {
        int start;
        int end;
    };

    bool cmp(const Interval &a, const Interval &b)
    {
        if (a.start == b.start)
        {
            return a.end < b.end;
        }
        return a.start < b.start;
    }

    int countWays(vector<vector<int>> &ranges)
    {
        vector<Interval> intervals;
        for (auto range : ranges)
        {
            Interval interval;
            interval.start = range[0];
            interval.end = range[1];
            intervals.push_back(interval);
        }
        sort(intervals.begin(), intervals.end(), [this](const Interval &a, const Interval &b)
             { return cmp(a, b); });
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            cout << intervals[i].start << ' ' << intervals[i].end << '\n';
        }
        const int mod = 1e9 + 7;
        int cnt = 1;
        long long res = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (intervals[i].end < intervals[i + 1].start)
            {
                cnt++;
            }
            else
            {
                intervals[i + 1].end = max(intervals[i + 1].end, intervals[i].end);
            }
        }
        cout << cnt << '\n';
        for (int i = 1; i <= cnt; i++)
        {
            res = (res * 2) % mod;
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> ranges = {{34, 56}, {28, 29}, {12, 16}, {11, 48}, {28, 54}, {22, 55}, {28, 41}, {41, 44}};
    cout << obj.countWays(ranges) << endl;
    return 0;
}
