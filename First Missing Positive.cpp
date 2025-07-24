// Problem link --->
https://leetcode.com/problems/first-missing-positive/description/

// Solutions --->

// My initial solution (so funny)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int find_one = 0;

        for (int i=0; i<n-1; ++i)
        {
            if(nums[i]==1)
              find_one = 1;
            
            if(nums[i]<=0)
            continue;

            else 
            {
                if (nums[i+1]-nums[i]>1 and find_one)
                 return nums[i]+1;
            }
        }

        if (!find_one and nums[n-1]!=1)
          return 1;

        return nums[n-1]+1;
    }
};

// Little bit better
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

// Easy solution (after long time)
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