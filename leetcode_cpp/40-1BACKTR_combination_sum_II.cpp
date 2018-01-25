//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "utils.h"
using namespace std;

class Solution {
public:
    void rec(vector<vector<int> > &res, int order, int target, vector<int> &local, vector<int> &candidates) {
        if (target == 0) {
            res.push_back(local);
            return;
        } else {
            for (int i = order; i < candidates.size(); ++i) {
                if (candidates[i] > target) return;
                if (i && candidates[i]==candidates[i-1] && i>order) continue;
                local.push_back(candidates[i]);
                rec(res, i+1, target-candidates[i], local, candidates);
                local.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> local;
        rec(res, 0, target, local, candidates);
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
