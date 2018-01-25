#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        vector<vector<int>> mem(courses.size(), vector<int>(courses.back()[1]+1, 0));
        return schedule(courses, 0, 0, mem);
    }

private:
    int schedule(vector<vector<int>>& courses, int i, int time, vector<vector<int>>& mem) {
        if (i >= courses.size()) return 0;
        if (mem[i][time]) return mem[i][time];

        int taken = 0;
        if (time + courses[i][0] <= courses[i][1]) {
            taken = 1 + schedule(courses, i+1, time + courses[i][0], mem);
        }
        int notTaken = schedule(courses, i+1, time, mem);
        mem[i][time] = max(taken, notTaken);
        return mem[i][time];
    }
};

int main() {
    vector<vector<int>> courses;

    courses = {
            {100, 200},
            {200, 1300},
            {1000, 1250},
            {2000, 3200}
    };
    cout << Solution().scheduleCourse(courses) << endl;
}
