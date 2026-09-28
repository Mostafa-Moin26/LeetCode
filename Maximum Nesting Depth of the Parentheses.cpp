// Problem link ------>
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

// Solution ----->
class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            }
            if (s[i] == ')') {
                cnt--;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};