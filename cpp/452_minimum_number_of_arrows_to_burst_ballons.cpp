//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {return a.second<b.second;};

        sort(points.begin(), points.end(), cmp);
        int count = 0;
        int shoot = -1;
        for (auto &p: points) {
            if (shoot == -1) {
                shoot = p.second;
                count++;
            } else if (p.first <= shoot && p.second >= shoot) {
                continue;
            } else {
                shoot = p.second;
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<pair<int, int>> points;

    points = {
            {7,10},
            {1,5},
            {3,6},
            {2,4},
            {1,4}
    };
    cout << Solution().findMinArrowShots(points) << endl;

    return 0;
}
