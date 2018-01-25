//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        // mem records the maximum subarray ended at i;
        vector<int> mem(nums.size());

        int m = nums[0];
        mem[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // the maximum subarray will be either previous maximum subarray ended at i-1 or i itself.
            mem[i] = max(nums[i], mem[i-1]+nums[i]);
            m = max(m, mem[i]);
        }
        return m;
    }
};

int main() {

    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;


    return 0;
}
