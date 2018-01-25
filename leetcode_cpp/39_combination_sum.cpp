//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;

class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        map<int, vector<vector<int> > > values;
        sort(candidates.begin(), candidates.end());
        for (auto &num: candidates) {
            vector<pair<int, vector<int> > > queue;
            for (int i = 1; i <= target/num; ++i) {
                for (auto &val: values) {
                    if (val.first+i*num > target) continue;
                    for (auto &v: val.second) {
                        vector<int> _v = v;
                        for (int j = 0; j < i; ++j) {
                            _v.push_back(num);
                        }
                        queue.push_back(make_pair(val.first+i*num, _v));
                    }
                }
                if (i*num > target) continue;
                vector<int> _v;
                for (int j = 0; j < i; ++j) {
                    _v.push_back(num);
                }
                if (!_v.empty()) queue.push_back(make_pair(i*num, _v));
            }
            for (auto &item: queue) {
                values[item.first].push_back(item.second);
            }
        }
        return values[target];
    }
};

int main() {
    vector<int> ints;

    ints = {2,3,6,7};
    cout << Solution().combinationSum(ints, 4) << endl;
    cout << Solution().combinationSum(ints, 7) << endl;
    cout << Solution().combinationSum(ints, 9) << endl;

    return 0;
}
