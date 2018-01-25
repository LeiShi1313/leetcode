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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> minHP(n, INT_MAX);

        int need;
        minHP[n-1] = 1;
        for (int i = m-1; i >= 0; --i) {
            need = minHP[n-1] - dungeon[i][n-1];
            minHP[n-1] = need <= 0 ? 1 : need;
            for (int j = n-2; j >= 0; --j) {
                need = min(minHP[j+1], minHP[j]) - dungeon[i][j];
                minHP[j] = need <= 0 ? 1 : need;
            }
        }
        return minHP[0];
    }
};

int main() {
    vector<vector<int>> grid;

    grid = {
            {0, -3}
    };
    cout << Solution().calculateMinimumHP(grid) << endl;

    grid = {
            {0,0,0},
            {1,1,-1}
    };
    cout << Solution().calculateMinimumHP(grid) << endl;

    grid = {
            {-2,-3,3},
            {-5,-10,1},
            {10,30,-5}
    };
    cout << Solution().calculateMinimumHP(grid) << endl;

    grid = {
            {1,-3,3},
            {0,-2,0},
            {-3,-3,-3}
    };
    cout << Solution().calculateMinimumHP(grid) << endl;
    return 0;
}
