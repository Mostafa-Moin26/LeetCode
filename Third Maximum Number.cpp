// Problem link ---->
https://leetcode.com/problems/third-maximum-number/description/

// Solution --->

// three pass
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long long first, second, third;
        first = second = third = LLONG_MIN;

        // find first max
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > first) {
                first = nums[i];
            }
        }

        // find second max
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > second && nums[i] < first) {
                second = nums[i];
            }
        }

        // find third max
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > third && nums[i] < second) {
                third = nums[i];
            }
        }

        return third == LLONG_MIN ? first : third;
    }
};

// one pass
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long long first, second, third;
        first = second = third = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == first || nums[i] == second || nums[i] == third) {
                continue;
            }

            if (nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if (nums[i] > second) {
                third = second;
                second = nums[i];
            } else if (nums[i] > third) {
                third = nums[i];
            }
        }

        return third == LLONG_MIN ? first : third;
    }
};

// Min-Heap 
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {

            if (seen.count(nums[i])) {
                continue;
            }

            pq.push(nums[i]);
            seen.insert(nums[i]);

            if (pq.size() > 3) {
                pq.pop();
            }
        }

        if (pq.size() < 3) {
            int mx = INT_MIN;

            while (!pq.empty()) {
                mx = max(mx, pq.top());
                pq.pop();
            }
            return mx;
        }

        return pq.top();
    }
};