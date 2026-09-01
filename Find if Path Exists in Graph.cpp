// Problem link --->
https://leetcode.com/problems/find-if-path-exists-in-graph/description/

// Solution ----->

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int parent = q.front();
            q.pop();

            if (parent == destination) {
                return true;
            }

            for (auto child : graph[parent]) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }

        return false;
    }
};