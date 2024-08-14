// Problem Link ----> 
https://leetcode.com/problems/integer-to-roman/description/


// Solutions ----->
// my solution (using % operator and no loop) 
class Solution {
public:
    string intToRoman(int num) {
        string s = "";

        s.append(num / 1000, 'M');
        num = num % 1000;
        if (num >= 900) {
            s.append("CM");
            num = num % 900;
        }
        s.append(num / 500, 'D');
        num  = num % 500;
        if (num >= 400) {
            s.append("CD");
            num = num % 400;
        }
        s.append(num / 100, 'C');
        num = num % 100;
        if(num >= 90) {
            s.append("XC");
            num = num % 90;
        }
        s.append(num / 50, 'L');
        num = num % 50;
        if (num >= 40) {
            s.append("XL");
            num = num % 40;
        }
        s.append(num / 10, 'X');
        num = num % 10;
        if (num == 9) {
            s.append("IX");
            num = num % 9;
        }
        s.append(num / 5, 'V');
        num = num % 5;
        if (num == 4) {
            s.append("IV");
            num = num % 4;
        }
        s.append(num, 'I');

        return s;
        
    }
};
