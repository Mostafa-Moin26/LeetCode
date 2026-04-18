// Problem link ---->
https://leetcode.com/problems/mirror-distance-of-an-integer/description/

// Solution --->
class Solution {
public:
    
    int rev(int n) {

        int r = 0;

        while (n) {
            r = r * 10 + (n % 10);
            n /= 10;
        }

        return r;
    }
    int mirrorDistance(int n) {

       return abs(n - rev(n)); 
    }
};