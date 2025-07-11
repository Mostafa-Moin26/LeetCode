// Problem link ---->
https://leetcode.com/problems/first-bad-version/description/?envType=problem-list-v2&envId=binary-search

// Optimal solution
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 0, high = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};