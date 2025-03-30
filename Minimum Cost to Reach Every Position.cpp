// Problem link ---->
https://leetcode.com/contest/weekly-contest-443/problems/minimum-cost-to-reach-every-position/?slug=longest-palindrome-after-substring-concatenation-ii&region=global_v2

// Solution
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;

        int n = cost.size();
        int curr = cost[0];

        for (int i = 1; i < n; i++) {
            if (curr < cost[i]) {
                cost[i] = curr;
            } else {
                curr = cost[i];
            }
        }

        return cost;
    }
};