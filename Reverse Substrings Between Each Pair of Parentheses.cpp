// Problem link ------>
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

// Solution ----->
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(curr);
                curr = "";
            } else if (s[i] == ')') {
                reverse(curr.begin(), curr.end());

                curr = st.top() + curr;
                st.pop();
            } else {
                curr += s[i];
            }
        }

        return curr;
    }
};