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
    void rec(vector<vector<int> > &res, vector<int> &candidates, int index, vector<int> &in, int target) {
        if (target == 0) {
            res.push_back(in);
            return;
        } else if (index >= candidates.size()) {
            return;
        } else if (target < 0) {
            return;
        }
        else {
            int i = 0;
            vector<int> in2 = in;
            while (index+i < candidates.size() && candidates[index]==candidates[index+i]) { ++i; }

            for (int j = 0; j <= i; ++j) {
                vector<int> tmp = in2;
                rec(res, candidates, index+i, tmp, target-j*candidates[index]);
                in2.push_back(candidates[index]);
            }

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> in;
        rec(res, candidates, 0, in, target);
        return res;
    }
};

int main() {
    vector<int> ints;
    clock_t start = clock();
    ints = {10, 1, 2, 7, 6, 1, 5};
    cout << Solution().combinationSum2(ints, 3) << endl;
    cout << Solution().combinationSum2(ints, 8) << endl;
    cout << Solution().combinationSum2(ints, 11) << endl;
    cout << Solution().combinationSum2(ints, 9) << endl;
    clock_t end = clock();
    cout << "Time used: " << end - start << endl;

    return 0;
}
