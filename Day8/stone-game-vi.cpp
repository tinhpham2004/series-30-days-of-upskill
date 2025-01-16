#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct TP
    {
        int value; // sum[i] = aliceValues[i] + bobValues[i];
        int index;
    };

    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        // loop bobValues => maxBob and secondMaxBox, idMaxBox and idSecondMaxBob
        int n = aliceValues.size();
        // {value, alice, bob}
        // sum[i] = aliceValues[i] + bobValues[i];
        TP sum[100001];

        for (int i = 0; i < n; i++)
        {
            sum[i].value = aliceValues[i] + bobValues[i];
            sum[i].index = i;
        }

        // sort(sum, sum+n);
        sort(sum, sum + n, [this](TP a, TP b)
             { return a.value < b.value; });

        // loop n-1 -> 0:
        // Alice's turn => alicePoint += aliceValues[sum[i].index]
        // Bob's turn => bobPoint += bobValues[sum[i].index]
        int alicePoints = 0, bobPoints = 0;
        bool isAliceTurn = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (isAliceTurn)
            {
                alicePoints += aliceValues[sum[i].index];
            }
            else
            {
                bobPoints += bobValues[sum[i].index];
            }
            isAliceTurn = !isAliceTurn;
        }
        // cout << alicePoints << ' ' << bobPoints << '\n';
        return alicePoints > bobPoints ? 1 : alicePoints == bobPoints ? 0
                                                                      : -1;
    }
};

int main()
{
    Solution obj;
    vector<int> aliceValues = {6, 5, 1, 2, 10, 6};
    vector<int> bobValues = {7, 7, 7, 7, 3, 7};
    cout << obj.stoneGameVI(aliceValues, bobValues);
    return 0;
}