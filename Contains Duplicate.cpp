// Problem link ---->
https://leetcode.com/problems/contains-duplicate/description/

// Solution --->

// Using Hash map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] >= 1) {
                return true;
            }
            mp[nums[i]]++;
        }

        return false;
    }
};

// Using Hash set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {

            if (st.count(nums[i])) {
                return true;
            }
            st.insert(nums[i]);
        }

        return false;
    }
};