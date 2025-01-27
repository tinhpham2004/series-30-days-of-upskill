#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(boxes[j] == '1') {
                    res[i] += abs(i-j);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    string boxes = "110";
    vector<int> res = sol.minOperations(boxes);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}