//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
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

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {

        auto Cmp = [](Interval a, Interval b) {return a.start < b.start;};
        auto it = lower_bound(vec.begin(), vec.end(), Interval(val, val), Cmp);
        int start = val, end = val;
        if (it != vec.begin() && (it-1)->end+1 >= val)
            it--;

        while (it != vec.end() && val+1 >= it->start && val-1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = vec.erase(it);
        }
        vec.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return vec;
    }

private:
    vector<Interval> vec;
};

int main() {

    SummaryRanges *obj = new SummaryRanges();

    vector<int> nums = {1,3,7,2,6};
    for (auto &num: nums) {
        obj->addNum(num);
    }
    vector<Interval> param_2 = obj->getIntervals();

    return 0;
}
