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

        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval,
                              [](Interval a, Interval b) { return a.end < b.start; });
        if (it != intervals.end()) {
            if (it->start > newInterval.end) {
                intervals.insert(it, newInterval);
            } else {
                auto first = it;
                for (it++; it != intervals.end();) {
                    if ((*it).end <= newInterval.end) {
                        intervals.erase(it);
                    } else {
                        break;
                    }
                }
                (*first).start = min(newInterval.start, (*first).start);
                if (it != intervals.end()) {
                    if ((*it).start > newInterval.end) {
                        (*first).end = max(newInterval.end, (*first).end);
                    } else {
                        (*first).end = max(newInterval.end, (*it).end);
                        intervals.erase(it);
                    }
                } else {

                    (*first).end = max(newInterval.end, (*first).end);
                }
            }

        } else {
            intervals.push_back(newInterval);
        }
        return intervals;
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
