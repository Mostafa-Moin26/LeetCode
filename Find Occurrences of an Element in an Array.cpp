// Problem link ---->
https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

// using map
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        int val = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                mp[val++] = i;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            
            if (mp.find(queries[i]) == mp.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(mp[queries[i]]);
            }
        }

        return ans;
    }
};

// Storing index
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> ans, index;

        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                index.push_back(i);
            }
        }

        for (auto q : queries) {
            if (q <= index.size()) {
                ans.push_back(index[q - 1]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};