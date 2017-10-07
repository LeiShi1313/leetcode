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
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> count(m, vector<int>(n, 0));
        int head, tail, i, j;
        for(i = 0; i < m; i++) {
            head = 0; tail = 0;
            for (j = 0; j < n; j++) {
                count[i][j] = grid[i][j] == '0' ? (count[i][j] + head) : 0;
                count[i][n-1-j] = grid[i][n-1-j] == '0' ? (count[i][n-1-j] + tail) : 0;
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[i][n-1-j] == 'W' ? 0 : (tail + (grid[i][n-1-j] == 'E' ? 1 : 0));
            }
        }
        for(j = 0; j < n; j++) {
            head = 0; tail = 0;
            for(i = 0; i < m; i++) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[m - 1 - i][j] = grid[m - 1 - i][j] != '0' ? 0 : (count[m - 1 - i][j] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[m - 1 - i][j] == 'W' ? 0 : (tail + (grid[m - 1 - i][j] == 'E' ? 1 : 0));
            }
        }
        int maxKill = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                maxKill = max(maxKill, count[i][j]);
            }
        }
        return maxKill;
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
