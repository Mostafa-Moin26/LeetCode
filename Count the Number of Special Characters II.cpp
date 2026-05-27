// Problem link ---->
https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/

// Solutions ----->
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        vector<int> special(26, 0);
        int cnt = 0;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (ch >= 'a' && ch <= 'z') {
                int idx = ch - 'a';

                lower[idx] = 1;

                if (upper[idx] && special[idx]) {
                    cnt--;
                    special[idx] = 0;
                }
            } else {
                int idx = ch - 'A';

                if (lower[idx] && !upper[idx]) {
                    cnt++;
                    special[idx] = 1;
                }
                
                upper[idx] = 1;
            }
        }

        return cnt;
    }
};