// Problem link --->
https://leetcode.com/problems/robot-return-to-origin/description/ 

// Solution --->
class Solution {
public:
    bool judgeCircle(string moves) {
        
        int up, down, left, right;
        up = down = left = right = 0;

        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'U') {
                up++;
            } else if (moves[i] == 'D') {
                down++;
            } else if (moves[i] == 'L') {
                left++;
            } else {
                right++;
            }
        }

        return up == down && left == right;
    }
};