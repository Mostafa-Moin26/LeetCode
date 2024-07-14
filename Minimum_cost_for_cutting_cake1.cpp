// Problem Link ---->
https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/description/

// solution ---->
class Solution {
public:
int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        
        int res = 0;
        int hc = 1, vc = 1;
        sort(h.begin(), h.end(), [](int a, int b){return a > b;});
        sort(v.begin(), v.end(), [](int a, int b){return a > b;});

        int idx1 = 0, idx2 = 0;

        for (int i = 0; i < h.size() + v.size(); ++i) {
            if (idx1 >= h.size()) {
                res += (v[idx2] * vc);
                hc++;
                idx2++;
            } else if (idx2 >= v.size()) {
                res += (h[idx1] * hc);
                vc++;
                idx1++;
            } else if (h[idx1] > v[idx2]) {
                res += (h[idx1] * hc);
                vc++;
                idx1++;
            } else {
                res += (v[idx2] * vc);
                hc++;
                idx2++;
            }
        }
        return res;
    }
};