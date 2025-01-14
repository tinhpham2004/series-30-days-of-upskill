#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int left = 0;
        int right = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int>> pqLeft;
        priority_queue<int, vector<int>, greater<int>> pqRight;
        long long res = 0;

        while (k--)
        {
            while (pqLeft.size() < candidates && left <= right)
            {
                pqLeft.push(costs[left]);
                left++;
            }

            while (pqRight.size() < candidates && right >= left)
            {
                pqRight.push(costs[right]);
                right--;
            }

            int minCostLeft = pqLeft.size() ? pqLeft.top() : INT_MAX;
            int minCostRight = pqRight.size() ? pqRight.top() : INT_MAX;

            if (minCostLeft <= minCostRight)
            {
                res += minCostLeft;
                pqLeft.pop();
            }
            else
            {
                res += minCostRight;
                pqRight.pop();
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k = 2;
    int candidates = 2;
    cout << sol.totalCost(costs, k, candidates) << endl;
    return 0;
}