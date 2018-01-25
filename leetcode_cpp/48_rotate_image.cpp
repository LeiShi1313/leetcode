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
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size() - 1;
        int rowSize, columnSize;
        if (n % 2 == 1) {
            rowSize = (n+1) / 2 - 1;
            columnSize = (n+1) / 2 - 1;
        } else {
            rowSize = (n+1) / 2 - 1;
            columnSize = (n+1) / 2;
        }
        for (int j = 0; j <= rowSize; j++) {
            for (int i = 0; i <= columnSize; i++) {
                int tmp = matrix[i][n-j];
                matrix[i][n-j] = matrix[j][i];
                matrix[j][i] = matrix[n-i][j];
                matrix[n-i][j] = matrix[n-j][n-i];
                matrix[n-j][n-i] = tmp;
            }
        }


    }
};

int main() {
    vector<vector<int>> matrix;

    matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    Solution().rotate(matrix);
    cout << matrix << endl;

    matrix = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };
    Solution().rotate(matrix);
    cout << matrix << endl;

    return 0;
}
