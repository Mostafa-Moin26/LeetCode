// Problem link ----->
https://leetcode.com/problems/jump-game-ii/description/

// Solutions ----->
// O(n) time and O(1) space
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int maxReach = nums[0];
        int steps = nums[0];
        int jumps = 1;

        for (int i = 1; i < n - 1; i++) {

            maxReach = max(maxReach, i + nums[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                steps = maxReach - i;
            }
        }

        return jumps;
    }
};