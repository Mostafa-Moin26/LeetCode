// Problem link ---->
https://leetcode.com/problems/count-and-say/description/

// Solution --->
class Solution {
public:

    string func(string& s) {
        string res = "";
        int cnt = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                res += to_string(cnt) + s[i - 1];
                cnt = 1;
            }
        }

        res += to_string(cnt) + s.back();

        return res;
    }
    string countAndSay(int n) {
        
        string result = "1";

        for (int i = 1; i < n; i++) {
            result = func(result);
        }

        return result;

    }
};