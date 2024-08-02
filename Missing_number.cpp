// Problem link --->
https://leetcode.com/problems/missing-number/description/

// solution --->

// using formula
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        n = (n * (n + 1)) / 2;
        int sum = 0;

        for (auto i : nums) sum += i;

        return n - sum;

    }
};

// using bitwise operator
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans = ans ^ i;

        for (int i = 0; i < n; ++i) ans = ans ^ nums[i];

        return ans;

    }
};