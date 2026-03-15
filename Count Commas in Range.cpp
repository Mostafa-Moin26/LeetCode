// Problem link ---->
https://leetcode.com/contest/weekly-contest-493/problems/count-commas-in-range/


// Solution ---->
class Solution {
public:
    int countCommas(int n) {

        if (n < 1000) {
            return 0;
        }

        return n - 999;
    }
};