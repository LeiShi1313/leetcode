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

        // could do it in binary search
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                break;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums;
    nums = {1,3,5,6};
    cout << Solution().searchInsert(nums, 5) << endl;

    return 0;
}
