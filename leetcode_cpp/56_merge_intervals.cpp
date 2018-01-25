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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;

        if (intervals.empty()) return ret;

        sort(intervals.begin(), intervals.end(),
        [](Interval a, Interval b) {return a.start< b.start;});

        ret.push_back(intervals[0]);
        for (auto&i: intervals) {
            if (ret.back().end < i.start) {
                ret.push_back(i);
            } else {
                ret.back().end = max(ret.back().end, i.end);
            }
        }
        return ret;

    }
};


int main() {

    vector<Interval> intervals= {
            Interval(1,3),
            Interval(2,6),
            Interval(0,10),
            Interval(15,18)
    };
    Interval* i = new Interval(1,2);
    cout << i << endl;
    cout << Solution().merge(intervals) << endl;
    return 0;
}
