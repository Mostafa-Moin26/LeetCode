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

