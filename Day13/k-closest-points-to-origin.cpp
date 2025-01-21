#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Point
    {
        int x;
        int y;
        double dis;
    };

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        vector<Point> vec;
        for (int i = 0; i < n; i++)
        {
            double dis = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            vec.push_back({points[i][0], points[i][1], dis});
        }

        sort(vec.begin(), vec.end(), [this](Point a, Point b)
             { return a.dis < b.dis; });

        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back({vec[i].x, vec[i].y});
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> res = sol.kClosest(points, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << endl;
}