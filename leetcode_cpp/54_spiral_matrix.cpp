//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ret;
        int n = matrix.size();
        if (n == 0) return ret;

        int m = matrix[0].size();

        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};


        vector<int> rc = {m, n-1};
        int x = 0, y = -1;
        int dir = 0;
        while (rc[dir%2]) {
            for (int i = 0; i < rc[dir%2]; i++) {
                x += dirs[dir][0];
                y += dirs[dir][1];
                ret.push_back(matrix[x][y]);
            }
            rc[dir%2]--;
            dir = (dir+1) % 4;
        }

        return ret;
    }
};

int main() {

    vector<vector<int>> matrix;

    matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    cout << Solution().spiralOrder(matrix) << endl;


    return 0;
}
