//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int s = 0;
        for (auto &num: nums) {
            s += num;
        }
        if (s % 2 == 1) return false;

        s /= 2;
        vector<vector<bool>> mem(nums.size()+1, vector<bool>(s+1, false));

        for (int i = 0; i <= nums.size(); i++) {
            mem[i][0] = true;
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j < s+1; j++) {
                mem[i][j] = mem[i-1][j];
                if (j >= nums[i-1]) {
                    mem[i][j] = mem[i][j] || mem[i-1][j-nums[i-1]];
                }
            }
        }
        return mem[nums.size()][s];
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
