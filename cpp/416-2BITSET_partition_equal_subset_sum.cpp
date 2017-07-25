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
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto n : nums) bits |= bits << n;
        return !(sum & 1) && bits[sum >> 1];
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
