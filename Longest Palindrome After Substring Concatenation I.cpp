// Problem link ---->
https://leetcode.com/contest/weekly-contest-443/problems/longest-palindrome-after-substring-concatenation-i/?slug=minimum-cost-to-reach-every-position&region=global_v2

// Solution
class Solution {

public:
    bool palindrome(string &s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++,right--;
        }
        return true;
    }
    vector<string> getSubStr(string &s) {
        vector<string> substr;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                substr.push_back(s.substr(i, j));
            }
        }
        return substr;
    }
    int compute(string s, string t) {
        vector<string> substr1 = getSubStr(s);
        vector<string> substr2 = getSubStr(t);

        int res = 0;

        for (string &it : substr1) {
            if (palindrome(it)) {
                if (it.size() > res) {
                    res = it.size();
                }
            }
        }
        for (string &it : substr2) {
            if (palindrome(it)) {
                if (it.size() > res) {
                    res = it.size();
                }
            }
        }

        for (string &it1 : substr1) {
            for (string &it2 : substr2) {
                string concate = it1 + it2;
                if (palindrome(concate)) {
                    if (concate.size() > res) {
                        res = concate.size();
                    }
                }
            }
        }
        return res;
    }
    int longestPalindrome(string s, string t) {
        int ans = compute(s, t);

        return ans;
    }
};