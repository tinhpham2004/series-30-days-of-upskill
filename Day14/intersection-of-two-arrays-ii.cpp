#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;

        int n = nums1.size();
        int m = nums2.size();

        for(int i=0;i<n;i++){
            mp1[nums1[i]]++;
        }

        for(int i=0;i<m;i++){
            mp2[nums2[i]]++;
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if (mp1[nums1[i]] > 0 && mp2[nums1[i]] > 0) {
                int times = min(mp1[nums1[i]], mp2[nums1[i]]);
                while (times--) {
                    res.push_back(nums1[i]);
                }
                mp1[nums1[i]] = 0;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> res = sol.intersect(nums1, nums2);
    for(auto item: res){
        cout << item << " ";
    }
}