#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        int n = seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int res = 0;
        for (int i = 0; i < n; i++)
            res += abs(students[i] - seats[i]);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> seats = {3, 1, 5};
    vector<int> students = {2, 7, 4};
    int res = sol.minMovesToSeat(seats, students);
    cout << res;
}