a// Problem link ---->
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

// Solutions ---->
class Solution {
public:
    bool check(vector<int>& nums) {

        int cnt = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {

            if (nums[i] > nums[i + 1]) {
                cnt++;
            }
        }
        if (cnt == 0) return true;
        else if (cnt == 1) {
            if (nums[0] >= nums[nums.size() - 1]) return true;
            else return false;
        } else {
            return false;
        }
        
    }
};

// little bit optimization
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size(); 

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) cnt++;
        }

        if (nums[n - 1] > nums[0]) cnt++;
        return cnt <= 1;
    }
};