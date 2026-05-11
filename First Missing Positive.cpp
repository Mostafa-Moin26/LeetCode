// Problem link --->
https://leetcode.com/problems/first-missing-positive/

// Solution --->

// sort + visited 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int visited[n+2];

        for (int i=1; i<n+2; i++)
        visited[i] = 0;

        for(int i=0; i<n; ++i)
        {
           if (nums[i]>0 && nums[i]<=n)
              visited[nums[i]] = 1;
        }

        int ans;
        for(int i=1; i<n+2; ++i)
        if(visited[i]==0)
        {
            ans = i;
            break;
        }
        return ans;
    }
};

// set
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int res = 1;

        for (int num : st) {

            if (st.find(res) == st.end()) {
                break;
            }
            res++;
        }

        return res;
    }
};

// Most Optimal 
/*
Key Idea:
- For an array of size n, the first missing positive
  must be in range [1, n+1].

Algorithm:
1. Place each number x at index (x-1)
   using swapping.
   Example:
   1 -> index 0
   2 -> index 1
   3 -> index 2

2. Ignore:
   - negative numbers
   - 0
   - numbers > n

3. After rearranging, scan the array:
   - if nums[i] != i+1,
     then answer = i+1

4. If all positions are correct,
   answer = n+1

Complexity:
- Time: O(n)
- Space: O(1)
*/

// Code 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};