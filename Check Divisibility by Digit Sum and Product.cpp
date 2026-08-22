// Problem link ---->
https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/description/

// Solution ---->

class Solution {
public:
    
    int helper(int n) {
        int s = 0, p = 1;

        while (n) {
            int dg = n % 10;
            n /= 10;
            s += dg;
            p *= dg;
        }

        return s + p;
    }
    bool checkDivisibility(int n) {

       return n % helper(n) == 0; 
    }
};