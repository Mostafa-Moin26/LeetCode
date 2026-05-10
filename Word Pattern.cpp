// Problem link ---->
https://leetcode.com/problems/word-pattern/description/

// Solution --->
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        vector<string> words;
        string tmp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(tmp);
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
        words.push_back(tmp);

        if (words.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];

            if (mp1.count(ch)) {
                if (words[i] != mp1[ch]) {
                    return false;
                }
            } else {
                if (mp2.count(words[i])) {
                    return false;
                }
                mp1[ch] = words[i];
                mp2[words[i]] = ch;
            }
        }

        return true;
    }
};