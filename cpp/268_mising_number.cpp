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
        int s = 0;
        int i = 0;
        while (i <= nums.size()) {s ^= i;i++;}
        i = 0;
        while (i < nums.size()) {s ^= nums[i++];}
        return s;
    }
};

int main() {
    vector<int> nums;

    nums = {0,1,3};
    cout << Solution().missingNumber(nums) << endl;

    nums = {0};
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}
