// Problem link ---->
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/


// Solution ---->
class Solution {
public:
    string removeDuplicates(string s) {
        
        string ans;

        for (int i = 0; i < s.size(); i++) {

            if (!ans.empty() && ans.back() == s[i]) {
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};