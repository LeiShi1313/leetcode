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
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid = 0;

        while (low <= high) {
            mid = low + (high-low) / 2;

            if ((mid == 0 || nums[mid] >= nums[mid-1]) &&
                    (mid == nums.size()-1 || nums[mid] >= nums[mid+1])) {
                return mid;
            } else if (mid > 0 && nums[mid-1] > nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return mid;
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,3,1};
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}
