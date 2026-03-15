// Problem link ---->
https://leetcode.com/contest/weekly-contest-493/problems/count-commas-in-range-ii/


// Solution ---->
class Solution {
public:
    long long countCommas(long long n) {

        if (n < 1000) {
            return 0;
        }
        long long ans = 0;
        long long i, c = 1;
        long long cnt, r;

        for (i = 1000; i <= n; i *= 1000) {
            r = i * 1000 - 1;
            cnt = min(n, r) - i +  1;

            if (cnt > 0) {
                ans += cnt * c;
            }
            c++;     
        }

        return ans;
    }
};