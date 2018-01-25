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
    bool search(vector<int>& nums, int target) {

        int low = 0, high = nums.size()-1;
        int mid;

        while (low <= high) {
            mid = (high + low) >> 1;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            } else if (nums[low] <= nums[mid]) {
                if (target < nums[mid] && nums[low] <= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target > nums[mid] && nums[high] >= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<int> nums;

    nums = {1,3,1,1,1};
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 3) << endl;
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 1) << endl;
    cout << Solution().search(nums, 1) << endl;

    return 0;
}
