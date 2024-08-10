// Problem link ----->

https://leetcode.com/problems/happy-number/description/

// solutions ------>
// using Floyd's cycle finding algorithm
class Solution {
public:
    
     int getSquareSum(int n) {

        int currSum = 0;

        while(n != 0) {

            int remainder = (n % 10);
            currSum += (remainder * remainder);
            n /= 10;
        }

        return currSum;
    }
    bool isHappy(int n) {

        int slow = getSquareSum(n);
        int fast = getSquareSum(getSquareSum(n));

        while ((slow != fast) && (fast != 1)) {

              slow = getSquareSum(slow);
              fast = getSquareSum(getSquareSum(fast));
        }

        return fast == 1;
    }
};
