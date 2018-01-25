//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        vector<pair<int, int>> times;

        for (auto &i: intervals) {
            times.push_back(make_pair(i.start, 1));
            times.push_back(make_pair(i.end, -1));
        }
        sort(times.begin(), times.end());

        int cur = 0;
        int maxR = 0;
        for (auto &time: times) {
            cur += time.second;
            maxR = max(maxR, cur);
        }
        return maxR;
    }
};



int main() {

    vector<Interval> intervals= {
            Interval(1,3),
            Interval(2,6),
            Interval(0,10),
            Interval(15,18)
    };
    cout << Solution().minMeetingRooms(intervals) << endl;

    intervals = {
            Interval(0,30),
            Interval(5, 10),
            Interval(15, 20)
    };
    cout << Solution().minMeetingRooms(intervals) << endl;
    return 0;
}
