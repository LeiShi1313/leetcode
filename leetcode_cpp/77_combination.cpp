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

class Solution {
public:
    void rec(vector<vector<int>> &ret, vector<int> &cur, int idx, int n, int k) {
        if (k == 0) {
            ret.push_back(cur);
            return;
        }
        if (idx > n) return;
        cur.push_back(idx);
        rec(ret, cur, idx+1, n, k-1);
        cur.pop_back();
        rec(ret, cur, idx+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> cur;
        rec(ret, cur, 1, n, k);
        return ret;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().combine(4, 2) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
