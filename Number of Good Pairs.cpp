// Problem link ---->
https://leetcode.com/problems/number-of-good-pairs/description/

// Solution --->

// Without Hash
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// Using Hash
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                ans += mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        
        return ans;
    }
};