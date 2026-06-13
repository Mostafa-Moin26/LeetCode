// Problem link ---->
https://leetcode.com/problems/weighted-word-mapping/description/

// Solution ---->
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string res;
  
        for (int i = 0; i < words.size(); i++) {

            int cnt = 0;

            for (char ch : words[i]) {
                cnt += weights[ch - 'a'];
            }
            
            res.push_back('z' - (cnt % 26));
        }

        return res;
    }
};