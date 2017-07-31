//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {

        vector<vector<int>> mem(n+1, vector<int>(n+1, 0));
        return DP(mem, 1, n);
    }

private:
    int DP(vector<vector<int>> &mem, int start, int end) {
        if (start >= end) return 0;
        if (mem[start][end] != 0) return mem[start][end];

        int res = INT_MAX;
        for (int i = start; i <= end; i++) {
            int tmp = i + max(DP(mem, start, i-1), DP(mem, i+1, end));
            res = min(res, tmp);
        }
        mem[start][end] = res;
        return res;
    }
};


int main() {

    cout << Solution().getMoneyAmount(10) << endl;
    cout << Solution().getMoneyAmount(5) << endl;
    cout << Solution().getMoneyAmount(4) << endl;
    return 0;
}
