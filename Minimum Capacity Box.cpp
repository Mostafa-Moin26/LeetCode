// Problem link ---->
https://leetcode.com/problems/minimum-capacity-box/description/

// Solution --->
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {

        int ans = INT_MAX;
        int idx;

        for (int i = 0; i < capacity.size(); i++) {

            if (capacity[i] >= itemSize) {
                if (ans > capacity[i]) {
                    ans = min(ans, capacity[i]);
                    idx = i;
                }
            }
        }

        if (ans == INT_MAX) {
            return -1;
        }
        return idx;
    }
};