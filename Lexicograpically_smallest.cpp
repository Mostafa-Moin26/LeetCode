
// Problem link --->
https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

// code --->
class Solution {
public:
    string getSmallestString(string s) {
        
        for (int i = 0; i < s.size() - 1; ++i) {
            int a = static_cast<int>(s[i]);
            int b = static_cast<int>(s[i + 1]);
            
            if (a % 2 == b % 2 || a & 1 == b & 1) {
               if (a > b) {
                   swap(s[i], s[i + 1]);
                   break;
               } 
            }
        }
        
        return s;
    }
};