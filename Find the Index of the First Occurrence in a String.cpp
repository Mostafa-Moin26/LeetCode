// Problem link --->
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Solution ---->
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {

            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};