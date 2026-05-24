// Problem link ---->
https://leetcode.com/problems/top-k-frequent-words/description/

// Solutions ----->

// without heap
class Solution {
public:
    
    static bool comp (pair<string, int> a, pair<string, int> b) {

        if (a.second == b.second) {
            return a.first < b.first;
        }

        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> mp;
        vector<pair<string, int>> v;

        for (auto x : words) {
            mp[x]++;
        }

        for (auto x : mp) {
            v.push_back(x);
        }

        sort(v.begin(), v.end(), comp);

        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);

        }

        return ans;
    }
};


// With heap
class Solution {
public:
    
    struct cmp {
        bool operator() (pair<string, int> a, pair<string, int> b) {

            if (a.second == b.second) {
                return a.first < b.first;
            }

            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> mp;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

        for (auto x : words) {
            mp[x]++;
        }

        for (auto x : mp) {
            pq.push(x);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};