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
        vector<bool> mem(n, false);
        set<int> canReach;

        canReach.insert(n-1);
        for (int i = n-2; i >= 0; i--) {
            int maxIdx = i+nums[i];
            auto it = canReach.lower_bound(maxIdx);
            if (it != canReach.begin()) {
                if (*prev(it) <= maxIdx)
                    canReach.insert(i);
            } else {
                if (*it <= maxIdx) canReach.insert(i);
            }
        }
        return canReach.find(0)!=canReach.end();
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
