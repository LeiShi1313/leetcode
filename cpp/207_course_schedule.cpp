#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        unordered_map<int, unordered_set<int>> suc,pre;
        unordered_set<int> courses;
        for (auto& p: prerequisites) {
            suc[p.second].insert(p.first);
            pre[p.first].insert(p.second);
        }
        for (int i = 0; i < numCourses; i++) courses.insert(i);
        for (auto& kv: pre) {
            courses.erase(kv.first);
        }
        int count = 0;
        while (!courses.empty()) {
            int c = *courses.begin();
            courses.erase(c);
            count++;
            for (auto& s: suc[c]) {
                pre[s].erase(c);
                if (pre[s].empty()) {
                    courses.insert(s);
                }
            }
        }
        return count >= numCourses;
    }
};

int main() {
    vector<pair<int, int>> prerequisites;
    int numCourses;

    prerequisites = {
            make_pair(1,0)
    };
    numCourses = 2;
    cout << Solution().canFinish(numCourses, prerequisites) << endl;

    prerequisites = {
            make_pair(1,0),
            make_pair(0,1)
    };
    numCourses = 2;
    cout << Solution().canFinish(numCourses, prerequisites) << endl;
    return 0;
}
