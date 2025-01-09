#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;
        if(nums1.size()%2 == 0 && nums2.size()%2 == 0) return 0;
        if(nums1.size()%2 == 1){
            for(int i=0;i<nums2.size();i++){
                res ^= nums2[i];
            }
        }
        if(nums2.size()%2 == 1){
            for(int i=0;i<nums1.size();i++){
                res ^= nums1[i];
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << sol.xorAllNums(nums1, nums2) << endl;
}
