// Problem link --->
https://leetcode.com/problems/reverse-string-prefix/description/

// Solution --->
class Solution {
public:
    string reversePrefix(string s, int k) {

        reverse(s.begin(), s.begin() + k);

        return s;
        
    }
};