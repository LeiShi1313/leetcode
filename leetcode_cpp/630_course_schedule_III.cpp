#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        auto cmp = [](vector<int>& a, vector<int>& b){return a[1] < b[1];};
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        int curTime = 0;
        for (auto& course: courses) {
            if (curTime + course[0] <= course[1]) {
                pq.push(course[0]);
                curTime += course[0];
            } else if (!pq.empty() && pq.top() > course[0]) {
                curTime += course[0] - pq.top();
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
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

    courses = {
            {5,5},{4,6},{2,6}
    };
    cout << Solution().scheduleCourse(courses) << endl;
}
