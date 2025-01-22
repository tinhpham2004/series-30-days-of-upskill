#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Infor
    {
        int dist;
        int speed;
    };
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();

        vector<Infor> vec;

        for (int i = 0; i < n; i++)
        {
            vec.push_back({dist[i], speed[i]});
        }

        sort(vec.begin(), vec.end(), [](Infor a, Infor b)
             { return a.dist * b.speed < a.speed * b.dist; });

        int curTime = 0;
        for (int i = 0; i < n; i++)
        {
            if (curTime * vec[i].speed < vec[i].dist)
            {
                curTime++;
            }
            else
            {
                break;
            }
        }

        return curTime;
    }
};

int main()
{
    Solution sol;
    vector<int> dist = {1, 3, 4};
    vector<int> speed = {1, 1, 1};
    cout << sol.eliminateMaximum(dist, speed);
}