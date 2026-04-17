// Problem link ---->
https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/

// Solution --->
class Solution {
public:
    
    int rev(int n) {

      int r = 0;

      while (n) {
        r = r * 10 + (n % 10);
        n /= 10;
      }  

      return r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int r = rev(n);

            if (mp.find(n) != mp.end()) {
                ans = min(ans, abs(i - mp[n]));
            }

            mp[r] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};