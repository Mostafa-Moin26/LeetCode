// Problem link --->
https://leetcode.com/problems/longest-common-prefix/description/

// Solution ---->
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool f = true;

        for (int i = 0; i < 200 && f; i++) {
            if (i >= strs[0].size()) {
                break;
            }
            char curr = strs[0][i];
            for (int j = 1; j < strs.size() && f; j++) {
                if (i >= strs[j].size() || strs[j][i] != curr) {
                    f = false;
                }
            }
            if (f) {
                ans += strs[0][i];
            }
        }

        return ans;
    }
};