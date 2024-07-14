// Problem Link --->
https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/description/

// Solution ---->
class Solution {
public:
long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        long res = 0;
        long horizontalBlocks = 1, verticalBlocks = 1;
        sort(horizontalCut.begin(), horizontalCut.end(), [](int a, int b){return a > b;});
        sort(verticalCut.begin(), verticalCut.end(), [](int a, int b){return a > b;});

        long long idx1 = 0, idx2 = 0;

        for (int i = 0; i < horizontalCut.size() + verticalCut.size(); ++i) {
            if (idx1 >= horizontalCut.size()) {
                res += (verticalCut[idx2] * verticalBlocks);
                horizontalBlocks++;
                idx2++;
            } else if (idx2 >= verticalCut.size()) {
                res += (horizontalCut[idx1] * horizontalBlocks);
                verticalBlocks++;
                idx1++;
            } else if (horizontalCut[idx1] > verticalCut[idx2]) {
                res += (horizontalCut[idx1] * horizontalBlocks);
                verticalBlocks++;
                idx1++;
            } else {
                res += (verticalCut[idx2] * verticalBlocks);
                horizontalBlocks++;
                idx2++;
            }
        }
        return res;
    }
};