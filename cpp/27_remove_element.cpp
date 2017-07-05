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
    int removeElement(vector<int>& nums, int val) {

        int idx = 0;
        for (auto &num: nums) {
            if (val != num) {
                swap(nums[idx++], num);
            }
        }
        return idx;
    }
};

int main() {
    vector<int> nums;
    nums = {3,2,2,2,3};
    cout << Solution().removeElement(nums, 3) << nums << endl;

    return 0;
}
