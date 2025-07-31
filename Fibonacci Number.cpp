// Problem link ------>
https://leetcode.com/problems/fibonacci-number/description/

// Solutions ------>
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        return fib(n - 1) + fib(n - 2);
    }
};

// using dp Tabulation method
class Solution {
public:
    int dp[32];

    int fib(int n) {
        
        dp[0] = 0, dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// using dp Memoization method
class Solution {
public:
    int dp[32];

    int fib(int n) {
        
        if (n <= 1) return n;

        if (dp[n] != 0) {
            return dp[n];
        }

        int res = fib(n - 1) + fib(n - 2);

        return res;
    }
};

// space optimization
class Solution {
public:

    int fib(int n) {
        
        if (n <= 1) return n;

        int res = 0;
        int first = 0, second = 1;

        for (int i = 2; i <= n; ++i) {

            res = first + second;
            first = second;
            second = res;
        }

        return res;
    }
};

// Using Binet's formula
class Solution {
public:
    int fib(int n) {
        
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        double res = (pow(phi, n) - pow(psi, n)) / sqrt5;

        return round(res);
    }
};

// Fastest approach
class Solution {
public:
    int fib(int n) {

        int fib_nums[] = {
            0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
            6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040,
            1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986,
            102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903
        };
        

        return fib_nums[n];
    }
};