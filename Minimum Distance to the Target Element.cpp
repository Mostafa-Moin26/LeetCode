// Problem link ----->
https://leetcode.com/problems/minimum-distance-to-the-target-element/description/

// Solution ---->
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int minIndex = 1001;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == target) {
                minIndex = min(minIndex, abs(i - start));
            }
        }

        return minIndex;
    }
};