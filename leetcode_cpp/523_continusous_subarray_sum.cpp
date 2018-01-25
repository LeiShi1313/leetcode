//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size(), pre = 0, mod;
        unordered_set<int> mem;
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
            mod = k==0 ? sum : sum%k;
            if (mem.find(mod) != mem.end()) return true;
            mem.insert(pre);
            pre = mod;
        }
        return false;
    }
};

int main() {
    vector<int> nums;

    nums = {23, 2, 4, 5, 13};
    cout << Solution().checkSubarraySum(nums, 6) << endl;

    return 0;
}
