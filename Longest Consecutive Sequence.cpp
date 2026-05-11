// Problem link ---->
https://leetcode.com/problems/longest-consecutive-sequence/description/


// Solution ---->

// sort
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int count = 1;
        int res = 1;

        for (int i = 0; i < nums.size() - 1; i++) {

            

            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] == nums[i + 1] - 1) {
                count++;
            } else {
                count = 1;
            }
            res = max(res, count);
        }

        return res;
    }
};


// set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int len = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    len++;
                }
                res = max(res, len);
            }
        }

        return res;
    }
};