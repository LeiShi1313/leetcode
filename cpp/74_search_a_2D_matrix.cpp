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
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n - 1;
        int i, j;
        while (low <= high) {
            int mid = (low + high) >> 1;
            i = mid / n;
            j = mid % n;
            if (target > matrix[i][j]) {
                low = mid + 1;
            } else if (target < matrix[i][j]) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;

    }
};

int main() {
    vector<vector<int>> matrix;

    matrix = {
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,50}
    };
    cout << Solution().searchMatrix(matrix, 3) << endl;
    cout << Solution().searchMatrix(matrix, 4) << endl;
    cout << Solution().searchMatrix(matrix, 11) << endl;
    cout << Solution().searchMatrix(matrix, 12) << endl;
    cout << Solution().searchMatrix(matrix, 16) << endl;

    matrix = {
            {1,1}
    };
    cout << Solution().searchMatrix(matrix, 1) << endl;
    cout << Solution().searchMatrix(matrix, 2) << endl;
    return 0;
}
