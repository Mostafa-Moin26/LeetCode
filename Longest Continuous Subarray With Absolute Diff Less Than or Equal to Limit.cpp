// Problem link ---->
https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

// Solution ---->

// Multiset
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j;
        multiset<int> m;

        for (j = 0; j < nums.size(); j++) {
            m.insert(nums[j]);

            if (*m.rbegin() - *m.begin() > limit) {
                m.erase(m.find(nums[i++]));
            } 
        }

        return j - i;
    }
};

// max & min heap
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> mx, mn;
        int i = 0, j;

        for (j = 0; j < nums.size(); j++) {

            while (!mx.empty() && nums[j] > mx.back()) {
                mx.pop_back();
            }
            while (!mn.empty() && nums[j] < mn.back()) {
                mn.pop_back();
            }
            mx.push_back(nums[j]);
            mn.push_back(nums[j]);

            if (mx.front() - mn.front() > limit) {
                if (mx.front() == nums[i]) mx.pop_front();
                if (mn.front() == nums[i]) mn.pop_front();
                i++;
            }
        }

        return j - i;
    }
};