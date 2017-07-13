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

        int low = 0, high = nums.size()-1;
        int mid, res = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {res = mid; break;}
            if (nums[low] <= nums[high]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target <= nums[high] && target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
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
    return 0;
}
