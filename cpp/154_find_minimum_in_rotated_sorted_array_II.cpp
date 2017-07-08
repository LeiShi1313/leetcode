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
    int findMin(vector<int>& nums) {

        int low = 0, high = nums.size()-1;
        int mid;

        while (low < high) {
            mid = (high + low) >> 1;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]){
                high = mid;
            } else {
                high--;
            }
        }
        return nums[low];

    }
};

int main() {
    vector<int> nums;

    nums = {1,3,1,1};
    cout << Solution().findMin(nums) << endl;

    nums = {3,3,1,3};
    cout << Solution().findMin(nums) << endl;

    nums = {1,3,3};
    cout << Solution().findMin(nums) << endl;

    nums = {3,3,1};
    cout << Solution().findMin(nums) << endl;

    return 0;
}
