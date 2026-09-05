// Problem link ----->
https://leetcode.com/problems/smallest-stable-index-ii/description/

// Solution ---->

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suff(n, 0);
        suff[n - 1] = nums[n - 1];

        for (int i = n - 2; ~i; i--) {
            if (nums[i] < suff[i + 1]) {
                suff[i] = nums[i];
            } else {
                suff[i] = suff[i + 1];
            }
        }

        int mx = -1;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if (mx - suff[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};