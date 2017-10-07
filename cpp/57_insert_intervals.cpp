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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

        vector<Interval> ret;
        auto it = intervals.begin();
        for (; it != intervals.end(); it++) {
            if (newInterval.start > it->end) {
                ret.push_back(*it);
            } else if (newInterval.end < it->start) {
                break;
            } else {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
        }

        ret.push_back(newInterval);
        for (; it != intervals.end(); it++) {
            ret.push_back(*it);
        }
        return ret;
    }
};


int main() {

    vector<Interval> intervals= {
            Interval(1,2),
            Interval(3,5),
            Interval(6,7),
            Interval(8,10),
            Interval(12,16)
    };
    Interval i = Interval(4,9);
    cout << Solution().insert(intervals, i) << endl;

    intervals= {
            Interval(1,2),
            Interval(3,5),
            Interval(6,7),
            Interval(9,10),
            Interval(12,16)
    };
    i = Interval(4,8);
    cout << Solution().insert(intervals, i) << endl;

    intervals = {
            Interval(1,5)
    };
    i = Interval(2,3);
    cout << Solution().insert(intervals, i) << endl;

    intervals = {
            Interval(1,5)
    };
    i = Interval(0,3);
    cout << Solution().insert(intervals, i) << endl;

    intervals = {
            Interval(1,5)
    };
    i = Interval(0,0);
    cout << Solution().insert(intervals, i) << endl;

    intervals = {
            Interval(2,5),
            Interval(6,7),
            Interval(8,9)
    };
    i = Interval(0,1);
    cout << Solution().insert(intervals, i) << endl;
    return 0;
}
