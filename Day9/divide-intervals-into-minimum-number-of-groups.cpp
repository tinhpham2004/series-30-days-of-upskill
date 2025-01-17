#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Interval
    {
        int left;
        int right;
    };

    int minGroups(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> events;

        // Create events for start and end of intervals
        for (const auto &interval : intervals)
        {
            events.push_back({interval[0], 1});       // Start of interval (+1)
            events.push_back({interval[1] + 1, -1}); // End of interval (-1)
        }

        // Sort events: by time, and type (-1 before +1 for same time)
        sort(events.begin(), events.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });

        int currentOverlap = 0;
        int maxOverlap = 0;

        // Sweep line algorithm to find maximum overlap
        for (const auto &event : events)
        {
            currentOverlap += event.second; // Update the overlap count
            maxOverlap = max(maxOverlap, currentOverlap);
        }

        return maxOverlap;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{441459, 446342}, {801308, 840640}, {871890, 963447}, {228525, 336985}, {807945, 946787}, {479815, 507766}, {693292, 944029}, {751962, 821744}};
    cout << sol.minGroups(intervals);
}