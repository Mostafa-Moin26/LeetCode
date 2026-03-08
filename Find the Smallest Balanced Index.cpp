// Problem link ---->
https://leetcode.com/problems/find-the-smallest-balanced-index/description/

// Solution --->
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        unsigned long long sum = 0;
        unsigned long long prod = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int idx = -1;

        for (int i = n - 1; i >= 0; i--) {

            sum -= nums[i];

            if (sum == prod) {
                idx = i;
            }

            if (prod > sum) {
                return idx;
            }
            prod *= nums[i];
        }

        return -1;
    }
};