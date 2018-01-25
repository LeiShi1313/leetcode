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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> OPT(m, vector<int>(n, INT_MAX));

        OPT[0][0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            OPT[0][j] = OPT[0][j-1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            OPT[i][0] = OPT[i-1][0] + grid[i][0];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; j++) {
                OPT[i][j] = min(OPT[i-1][j], OPT[i][j-1]) + grid[i][j];
            }
        }
        return OPT[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> grid;

    grid = {
            {1,2,3,4},
            {4,3,2,1},
            {2,2,2,2}
    };
    cout << Solution().minPathSum(grid) << endl;

    return 0;
}
