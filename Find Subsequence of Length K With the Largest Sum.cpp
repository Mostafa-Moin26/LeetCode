// Problem link ---->
https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

// Solution ---->
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        if (k == nums.size()) {
            return nums;
        }
        vector<int> temp(nums.begin(), nums.end()); 
        
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        map<int, int> mp; 

        for (int i = 0; i < k; i++) {
            mp[temp[i]]++;
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            if (mp.find(nums[i]) != mp.end()) {
                if (mp[nums[i]] > 0) {
                    ans.push_back(nums[i]);
                }
                mp[nums[i]]--;
            }
        }

        return ans;
    }
};