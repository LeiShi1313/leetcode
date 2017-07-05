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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1;
        int last = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[last])
                continue;
            last++;count++;
            swap(nums[i],nums[last]);
        }
        return count;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> nums;

    nums = {};
    cout << Solution().removeDuplicates(nums) << nums << endl;
    nums = {1,1,2};
    cout << Solution().removeDuplicates(nums) << nums << endl;
    nums = {1,2,3,3,3,3,4,5};
    cout << Solution().removeDuplicates(nums) << nums << endl;
    nums = {1,2,3,3,3,3,4,4,4,4,5};
    cout << Solution().removeDuplicates(nums) << nums << endl;
    nums = {1,2,3,3,3,3,4,5,5,5,5};
    cout << Solution().removeDuplicates(nums) << nums << endl;
    nums = {1,1,1};
    cout << Solution().removeDuplicates(nums) << nums << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
