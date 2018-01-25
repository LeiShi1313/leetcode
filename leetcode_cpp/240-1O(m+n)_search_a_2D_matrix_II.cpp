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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target)
                return true;

            if (matrix[i][j] < target)
                i++;
            else
                j--;
        }

        return false;
    }

};

int main() {
    vector<vector<int>> matrix;

    matrix = {
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30}
    };
    cout << Solution().searchMatrix(matrix, 5) << endl;
    cout << Solution().searchMatrix(matrix, 20) << endl;

    matrix = {
            {1,1}
    };
    cout << Solution().searchMatrix(matrix, 1) << endl;
    cout << Solution().searchMatrix(matrix, 2) << endl;
    return 0;
}
