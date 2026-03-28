// Problem link --->
https://leetcode.com/contest/biweekly-contest-179/problems/minimum-absolute-difference-between-two-values/description/


// Solution --->

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {

        int ans = 101;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] != 0 && nums[j] != nums[i]) {
                        ans = min(ans, abs(i - j));
                        break;
                    }
                }
            }
        }

        return ans == 101 ? -1 : ans;
    }
};©leetcode