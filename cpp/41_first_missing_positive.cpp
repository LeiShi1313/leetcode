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
    int missingNumber(vector<int>& nums) {

        int i;
        for (i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] != nums[nums[i]-1] && nums[i] <= nums.size()) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        i = 1;
        for (auto &num: nums) {
            if (num != i) {
                return i;
            }
            i++;
        }
        return i;
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,0};
    cout << Solution().missingNumber(nums) << endl;

    nums = {3,4,-1,1};
    cout << Solution().missingNumber(nums) << endl;

    nums = {1,1};
    cout << Solution().missingNumber(nums) << endl;

    nums = {0,0,4};
    cout << Solution().missingNumber(nums) << endl;

    nums = {3,4,2,2,9,5,1,13,-1,-1,-4,3,15,-10,6,10};
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}
