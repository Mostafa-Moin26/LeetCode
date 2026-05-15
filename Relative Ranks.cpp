// Problem link ---->
https://leetcode.com/problems/relative-ranks/description/

// Solutions ---->

// using priority queue (max heap)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int i = 1;

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            int currIndx = p.second;
            pq.pop();

            if (i == 1) {
                ans[currIndx] = "Gold Medal";
            } else if (i == 2) {
                ans[currIndx] = "Silver Medal";
            } else if (i == 3) {
                ans[currIndx] = "Bronze Medal";
            } else {
                ans[currIndx] = to_string(i);    
            }
            i++;
        } 

        return ans;
    }
};

// sort + map
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        unordered_map<int, string> mp;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                mp[sortedScore[i]] = "Gold Medal";
            } else if (i == 1) {
                mp[sortedScore[i]] = "Silver Medal";
            } else if (i == 2) {
                mp[sortedScore[i]] = "Bronze Medal";
            } else {
                mp[sortedScore[i]] = to_string(i + 1);
            }
        }

        vector<string> ans;

        for (int s : score) {
            ans.push_back(mp[s]);
        }

        return ans;
    }
};