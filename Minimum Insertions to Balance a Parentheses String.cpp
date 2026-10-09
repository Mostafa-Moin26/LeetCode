// Problem link ------>
https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/


// Solution ------>
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, cnt = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else {
                if (i < n - 1 && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }
                if (cnt == 0) {
                    ans++;
                } else {
                    cnt--;
                }
            }
        }

        return ans + 2 * cnt;
    }
};