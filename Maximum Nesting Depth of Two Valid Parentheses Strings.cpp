// Problem link ------>
https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/

// Solution ----->

// using stack
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        stack<pair<char, int>> st;
        vector<int> ans;

        for (char ch : seq) {
            if (st.empty()) {
                st.push({ch, 0});
                ans.push_back(0);
            } else if (ch == '(') {
                if (st.top().second == 0) {
                    st.push({ch, 1});
                    ans.push_back(1);
                } else {
                    st.push({ch, 0});
                    ans.push_back(0);
                }
            } else {
                if (st.top().second == 0) {
                    ans.push_back(0);
                } else {
                    ans.push_back(1);
                }
                st.pop();
            }
        }

        return ans;
    }
};


// Beats 100%
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        vector<int> ans(seq.size());
        int depth = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};