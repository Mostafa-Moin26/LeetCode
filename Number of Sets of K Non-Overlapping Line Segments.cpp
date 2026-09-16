// Problem link ----->
https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/

// Solution ---->

class Solution {
public:
    const long long MOD = 1000000007LL;

    long long modPow(long long base, long long exp) {
        long long res = 1;

        while (exp) {
            if (exp & 1LL) {
                res = res * base % MOD;
            }
            base = base * base % MOD;
            exp >>= 1LL;
        } 

        return res;
    }

    int numberOfSets(int n, int k) {
        long long N = n + k - 1;
        long long R = 2LL * k;

        R = min(R, N - R);

        long long numerator = 1;
        long long denominator = 1;

        for (long long i = 1; i <= R; i++) {
            numerator = numerator * (N - R + i) % MOD;
            denominator = denominator * i % MOD;
        }

        long long inverse = modPow(denominator, MOD - 2);

        return static_cast<int>(numerator * inverse % MOD);
    }
};