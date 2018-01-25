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
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mem;
        int count = 0, sum = 0;
        mem[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (mem.find(sum-k) != mem.end())
                count += mem[sum-k];
            mem[sum]++;
        }
        return count;
    }
};

int main() {
    vector<int> nums;

    nums = {1,1,1};
    cout << Solution().subarraySum(nums, 2) << endl;

    cout << Solution().subarraySum(nums, 3) << endl;

    return 0;
}
