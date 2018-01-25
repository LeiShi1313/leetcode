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
    void rec(vector<int> &nums, int i, int &count, int S) {
        if (i == nums.size()) {
            if (S == 0)
                count++;
            return;
        }
        rec(nums, i+1, count, S-nums[i]);
        rec(nums, i+1, count, S+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int count = 0;
        rec(nums, 0, count, S);
        return count;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> nums = {1,1,1,1,1};
    cout << Solution().findTargetSumWays(nums,3) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
