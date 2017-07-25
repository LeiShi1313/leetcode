//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<int> pre(n, 1);
        for (int i = 1; i < n; ++i) {
            pre[i] = obstacleGrid[0][i] == 1 ? 0 : (pre[i-1] == 0 ? 0 : 1);
        }

        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0]) {
                pre[0] = 0;
            }
            for (int j = 1; j < n; ++j) {
                pre[j] = obstacleGrid[i][j] == 1 ? 0 : (
                        (obstacleGrid[i][j-1] == 1
                        ? 0 : pre[j-1])
                      + (obstacleGrid[i-1][j] == 1
                        ? 0 : pre[j]));
            }
        }

        return pre[n-1];
    }
};

int main() {
    vector<vector<int>> grid;

    grid = {
            {1}
    };
    cout << Solution().uniquePathsWithObstacles(grid) << endl;

    grid = {
            {0,0},
            {1,1},
            {0,0}
    };
    cout << Solution().uniquePathsWithObstacles(grid) << endl;

    grid = {
            {0,0,0},
            {0,1,0},
            {0,0,0}
    };
    cout << Solution().uniquePathsWithObstacles(grid) << endl;


    grid = {
            {0,0,0,0,0},
            {0,1,1,1,0},
            {0,0,0,1,0},
            {0,1,1,1,0},
            {0,0,0,0,0}
    };
    cout << Solution().uniquePathsWithObstacles(grid) << endl;
    return 0;
}
