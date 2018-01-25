//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;
        int maxIdx;

        for (int i = 0; i < n-1; i++) {
            if (maxIdx <= i && nums[i] == 0) return false;
            if (i+nums[i] > maxIdx) {
                maxIdx = i + nums[i];
            }
            if (maxIdx >= n-1) return true;
        }

        return false;
    }
};


int main() {
    vector<int> nums;

    nums = {2,5,0,0};
    cout << Solution().canJump(nums) << endl;

    nums = {2,0};
    cout << Solution().canJump(nums) << endl;

    nums = {2,3,1,1,4};
    cout << Solution().canJump(nums) << endl;

    nums = {3,2,1,0,4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}
