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
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix[0].size();
        int n = matrix.size();

        bool rowMap[n];
        memset(rowMap, false, sizeof(bool)*n);
        bool columnMap[m];
        memset(columnMap, false, sizeof(bool)*m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rowMap[i] = true;
                    columnMap[j] = true;
                }
            }
        }
        for (int k = 0; k < n; k++) {
            if (rowMap[k]) {
                for (int i = 0; i < m; i++) {
                    matrix[k][i] = 0;
                }
            }
        }
        for (int k = 0; k < m; k++) {
            if (columnMap[k]) {
                for (int i = 0; i < n; i++) {
                    matrix[i][k] = 0;
                }
            }
        }

    }
};

int main() {
    vector<vector<int>> matrix;

    matrix = {
            {0,0,0,5},
            {4,3,1,4},
            {0,1,1,4},
            {1,2,1,3},
            {0,0,1,1}
    };
    Solution().setZeroes(matrix);
    cout << matrix << endl;

    return 0;

};
