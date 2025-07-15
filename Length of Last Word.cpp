// Problem link --->
https://leetcode.com/problems/length-of-last-word/

// Solution ---->
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int cnt = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] != ' ') {
                cnt++;
            } else {
                if (cnt != 0) {
                    break;
                }
            }
        }

        return cnt;
    }
};