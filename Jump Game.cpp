// Problem link ----->
https://leetcode.com/problems/jump-game/description/

// Solutions ----->
// O(n) time and O(1) space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        if (nums[0] == 0) return false;

        int maxReach = nums[0];
        int steps = nums[0];

        for (int i = 1; i < n; i++) {

            if (i == n - 1) return true;

            maxReach = max(maxReach, i + nums[i]);
            steps--;

            if (steps == 0) {

                if (i >= maxReach) return false;

                steps = maxReach - i;
            }
        }

        return false;
    }
};