//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& nums, int start, int target) {
        if (target <= 0) return target == 0;
        for (int i = start; i < nums.size(); i++)
            if (backtrack(nums, i + 1, target - nums[i])) return true;
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return !(sum & 1) && backtrack(nums, 0, sum >> 1);
    }
};

int main() {
    vector<int> nums;

    nums = {1, 5, 11, 5};
    cout << Solution().canPartition(nums) << endl;

    nums = {1, 2, 3, 5};
    cout << Solution().canPartition(nums) << endl;

    return 0;
}
