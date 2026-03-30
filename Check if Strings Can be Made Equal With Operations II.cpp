// Problem link --->
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/

// Solution --->
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        int n = s1.size();

        map<char, int> even1, even2, odd1, odd2;

        for (int i = 0; i < n; i++) {

            if (i & 1) {
                odd1[s1[i]]++;
                odd2[s2[i]]++;
            } else {
                even1[s1[i]]++;
                even2[s2[i]]++;
            }
        }

        return even1 == even2 && odd1 == odd2;
    }
};

// using sort
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        int n = s1.size();

        string even1, even2, odd1, odd2;
        even1 = even2 = odd1 = odd2 = "";

        for (int i = 0; i < n; i++) {

            if (i & 1) {
                odd1 += s1[i];
                odd2 += s2[i];
            } else {
                even1 += s1[i];
                even2 += s2[i];
            }
        }

        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        return even1 == even2 && odd1 == odd2;
    }
};