#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0, rowCnt, colCnt[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!j || grid[i][j-1] == 'W') {
                    rowCnt = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++) {
                        rowCnt += grid[i][k] == 'E';
                    }
                }
                if (!i || grid[i-1][j] == 'W') {
                    colCnt[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++) {
                        colCnt[j] += grid[k][j] == 'E';
                    }
                }
                if (grid[i][j] == '0') res = max(res, rowCnt + colCnt[j]);
            }
        }
        return res;
    }
};

int main() {

    vector<vector<char>> grid;

    grid = {
            {'0', 'E', '0', '0'},
            {'E', '0', 'W', 'E'},
            {'0', 'E', '0', '0'}
    };
    cout << Solution().maxKilledEnemies(grid) << endl;

    grid = {
            {'0', 'E'}
    };
    cout << Solution().maxKilledEnemies(grid) << endl;

    grid = {
            {'0', 'E', '0', 'W'}
    };
    cout << Solution().maxKilledEnemies(grid) << endl;
    return 0;
}
