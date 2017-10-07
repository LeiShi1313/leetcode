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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(),
             [&](Interval a, Interval b) {return a.start<b.start;});

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};



int main() {

    vector<Interval> intervals= {
            Interval(1,3),
            Interval(2,6),
            Interval(0,10),
            Interval(15,18)
    };
    cout << Solution().canAttendMeetings(intervals) << endl;

    intervals = {
            Interval(0,30),
            Interval(5, 10),
            Interval(15, 20)
    };
    cout << Solution().canAttendMeetings(intervals) << endl;
    return 0;
}
