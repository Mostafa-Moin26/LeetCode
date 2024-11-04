// Problem link ---->
https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// Solutions ---->
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;

        for (int i = 0; i < nums1.size(); i++) a.push_back(nums1[i]);
        for (int i = 0; i < nums2.size(); i++) a.push_back(nums2[i]);

        sort(a.begin(), a.end());

        double ans;
        int n = a.size();

        if (n & 1) {
            ans = a[n / 2];
        } else {
            ans = (a[n / 2 - 1] + a[n / 2]) / 2.0;
        }

        return ans;
    }
};