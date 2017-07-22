//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {

        map<int, vector<int>> mem;

        int idx = 0;
        for (auto &i: intervals) {
            mem[i.start].push_back(idx++);
        }

        vector<int> ret;

        idx = 0;
        bool found = false;
        for (auto &i: intervals) {
            auto it = mem.lower_bound(i.end);
            if (it != mem.end()) {
                found = false;
                for (auto &_idx: it->second) {
                    if (_idx != idx) {
                        found = true;
                        ret.push_back(_idx);
                        break;
                    }
                }
                if (!found) {
                    ret.push_back(-1);
                }
                idx++;
            } else {
                ret.push_back(-1);
                idx++;
            }
        }

        return ret;
    }
};

int main() {
    vector<Interval> intervals;

    intervals = {
            Interval(1,2)
    };
    cout << Solution().findRightInterval(intervals) << endl;

    intervals = {
            Interval(3,4),
            Interval(2,3),
            Interval(1,2)
    };
    cout << Solution().findRightInterval(intervals) << endl;

    intervals = {
            Interval(1,4),
            Interval(2,3),
            Interval(3,4)
    };
    cout << Solution().findRightInterval(intervals) << endl;


    return 0;
}
