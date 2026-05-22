// Problem link ---->
https://leetcode.com/problems/detect-squares/description/

// Solution ---->
class DetectSquares {
public:
    int cnt[1001][1001] = {};
    vector<pair<int, int>> points;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
        points.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
     int x1 = point[0];
     int y1 = point[1];
     int ans = 0;

     for (auto p : points) {
        int x3 = p.first;
        int y3 = p.second;

        if (abs(x3 - x1) == 0 || abs(x3 - x1) != abs(y3 - y1)) {
            continue;
        }

        ans += cnt[x1][y3] * cnt[x3][y1];
     }  

     return ans; 
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */