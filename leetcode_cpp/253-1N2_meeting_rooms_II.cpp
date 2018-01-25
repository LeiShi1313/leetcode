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
        sort(intervals.begin(), intervals.end(),
             [&](Interval a, Interval b) {return a.start<b.start;});

        int count;
        int maxR = 1;
        for (int i = 1; i < intervals.size(); i++) {
            count = 1;
            for (int j = i-1; j >= 0; j--) {
                if (intervals[j].end > intervals[i].start) {
                    maxR = max(maxR, ++count);
                }
            }
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
