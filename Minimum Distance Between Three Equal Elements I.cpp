// Problem link ---->
https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/

// Solution --->
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int res = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        res = min(res, abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};