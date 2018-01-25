#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<unordered_set<int>> map(numCourses);
        vector<int> courses(numCourses, 0);

        for (auto& p: prerequisites) {
            map[p.second].insert(p.first);
            courses[p.first]++;
        }
        vector<int> ret;
        queue<int> toVisit;
        for (int i = 0; i < numCourses; i++) {
            if (!courses[i]) {
                toVisit.push(i);
            }
        }
        while (!toVisit.empty()) {
            int front = toVisit.front();
            ret.push_back(front);
            toVisit.pop();
            for (auto& c: map[front]) {
                courses[c]--;
                if (courses[c] == 0)
                    toVisit.push(c);
            }
        }


        return ret.size() == numCourses ? ret : vector<int>{};
    }
};

int main() {
    vector<pair<int, int>> prerequisites;
    int numCourses;

    prerequisites = {
            make_pair(1,0)
    };
    numCourses = 2;
    cout << Solution().findOrder(numCourses, prerequisites) << endl;

    prerequisites = {
            make_pair(1,0),
            make_pair(2,0),
            make_pair(3,1),
            make_pair(3,2)
    };
    numCourses = 4;
    cout << Solution().findOrder(numCourses, prerequisites) << endl;

    prerequisites = {};
    numCourses = 2;
    cout << Solution().findOrder(numCourses, prerequisites) << endl;
    return 0;
}
