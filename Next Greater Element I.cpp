// Problem link ---->
https://leetcode.com/problems/next-greater-element-i/description/

// Solution --->
// Monotonic stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; ~i; i--) {

            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            mp[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> res;

        for (int num : nums1) {
            res.push_back(mp[num]);
        }

        return res;
    }
};