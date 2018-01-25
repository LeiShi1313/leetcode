//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() -1);
    }

private:
    int majority(vector<int> &nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid+1, right);
        if (lm == rm) return lm;
        return count(nums.begin()+left, nums.begin()+right+1, lm) >
               count(nums.begin()+left, nums.begin()+right+1, rm) ?
               lm:rm;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> nums = {6,5,5};
    cout << Solution().majorityElement(nums) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
