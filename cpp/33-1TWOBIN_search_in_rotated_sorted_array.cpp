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
    int search(vector<int>& nums, int target) {

        if (nums.empty()) return -1;
        int low = 0, high = nums.size()-1;
        int mid, min, res = -1;

        while (low < high) {
            mid = (high + low) >> 1;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        min = low;

        if (target <= nums.back()) {
            low = min;
            high = nums.size()-1;
        } else {
            low = 0;
            high = min - 1;
        }

        while (low <= high) {
            mid = (high + low) >> 1;
            if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                res = mid;
                break;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums;

    nums = {4,5,6,7,0,1,2};
    cout << Solution().search(nums, 4) << endl;
    cout << Solution().search(nums, 5) << endl;
    cout << Solution().search(nums, 6) << endl;
    cout << Solution().search(nums, 7) << endl;
    cout << Solution().search(nums, 0) << endl;
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 2) << endl;

    nums = {5,1,3};
    cout << Solution().search(nums, 5) << endl;
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 3) << endl;

    nums = {5,1,2,3,4};
    cout << Solution().search(nums, 5) << endl;
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 2) << endl;
    cout << Solution().search(nums, 3) << endl;
    cout << Solution().search(nums, 4) << endl;

    nums = {1,3};
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 3) << endl;

    nums = {3,1};
    cout << Solution().search(nums, 3) << endl;
    cout << Solution().search(nums, 1) << endl;

    nums = {1,2,3};
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 2) << endl;
    cout << Solution().search(nums, 3) << endl;

    nums = {};
    cout << Solution().search(nums, 4) << endl;
    return 0;
}
