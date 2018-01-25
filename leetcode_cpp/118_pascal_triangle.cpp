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
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.push_back({1});
        if (numRows == 1) {
            return res;
        }
        for (int level = 2; level <= numRows; level++) {
            vector<int> row(level, 1);
            for (int j = 1; j < level-1; j++) {
                row[j] = res[level-2][j-1] + res[level-2][j];
            }
            res.push_back(row);
        }

        return res;
    }
};

int main() {

    cout << Solution().generate(5) << endl;
    return 0;
}
