// Problem Link  ---->
https://leetcode.com/problems/find-the-encrypted-string/submissions/1320879278/

// solution ---->
class Solution {
public:
    string getEncryptedString(string s, int k) {
        
        string res = s;
        for (int i = 0; i < s.size(); ++i) {
            res[i] = s[k % s.size()];
            k++;
        }

        return res;
    }
};