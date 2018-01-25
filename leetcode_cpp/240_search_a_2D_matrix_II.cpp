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

        int row=0;
        int low = 0, high = matrix.size()-1;
        int mid;

        while (low < high) {
            mid = (low + high) >> 1;
            if (target < matrix[mid][0]) {
                high = mid - 1;
            } else if (target > matrix[mid][0]) {
                high--;
            } else {
                return true;
            }
        }
        for (row=low; row<m; row++ ) {
            if (binarySearch(matrix[row], target))
                return true;
        }
        
        return false;
    }

private:
    bool binarySearch(vector<int> &nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;

        while (low <= high) {
            mid = (low + high) >> 1;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
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
