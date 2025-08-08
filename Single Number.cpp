// Problem Link ----->
https://leetcode.com/problems/single-number/description/


// Solutions ----->

// using xor
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) ans ^= nums[i];


        return ans;
        
    }
};

// Beats 100%
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0];

        int singleNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            singleNum ^= nums[i];
        }

        return singleNum;
    }
};

// using map
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        map<int, int> mp;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for (auto i : mp) {
            if (i.second == 1) {
                ans = i.first;
                break;
            }
        }

        return ans;
        
    }
};

// sort the array
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i += 2) {

            if (nums[i] != nums[i - 1]) {
                return nums[i - 1];
            }
        }

        return nums[nums.size() - 1];
    }
};