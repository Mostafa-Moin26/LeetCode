// Problem link ---->
https://leetcode.com/problems/next-permutation/description/

// Solutions

// using STL
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

//Optimized solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int idx = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            sort(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i > idx; i--) {
                if (nums[i] > nums[idx]) {
                    swap(nums[i], nums[idx]);
                    break;
                }
            }
            sort(nums.begin() + idx + 1, nums.end());
        }
    }
};

// also Optimized code
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int i = n - 1;

        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }

        if (i == 0) {
            sort(nums.begin(), nums.end());
            return;
        } 

        int j = n - 1;

        while (j >= i && nums[j] <= nums[i - 1]) {
            j--;
        }

        swap(nums[i - 1], nums[j]);
        sort(nums.begin() + i, nums.end());
        
    }
};