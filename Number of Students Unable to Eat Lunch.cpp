// Problem link --->
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

// Solutions --->

// Using queue
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        int cnt[2] = {};

        for (int i = 0; i < students.size(); i++) {
            q.push(students[i]);
            cnt[students[i]]++;
        }

        int i = 0;
        while (!q.empty()) {
            int student = q.front();

            if (student == sandwiches[i]) {
                i++;
                cnt[student]--;
            } else {
                if (!cnt[sandwiches[i]]) {
                    break;
                }
                q.push(student);
            }
            q.pop();
        }

        return q.size();


    }
};


// Without queue
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int cnt[2] = {};

        for (int i = 0; i < students.size(); i++) {
            cnt[students[i]]++;
        }

        for (int i = 0; i < sandwiches.size(); i++) {

            if (cnt[sandwiches[i]] == 0) {
                return sandwiches.size() - i;
            }
            cnt[sandwiches[i]]--;
        }

        return 0;

    }
};