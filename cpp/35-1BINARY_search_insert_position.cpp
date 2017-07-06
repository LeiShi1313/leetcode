//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;

        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums;
    nums = {1,3,5,6};
    cout << Solution().searchInsert(nums, 2) << endl;

    return 0;
}
