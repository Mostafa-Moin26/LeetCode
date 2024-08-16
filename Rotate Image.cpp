// Problem link ----->
https://leetcode.com/problems/rotate-image/description/

// solutions ----->
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>> mat = matrix;
        int n = matrix.size();
        int k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0,k = n - 1; j < n; ++j, --k) {
                matrix[i][j] = mat[k][i];
            }
        }
    }
};