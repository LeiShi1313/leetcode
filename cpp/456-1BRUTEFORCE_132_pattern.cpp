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
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        for (int i = 0; i < nums.size()-2; i++) {
            for (int j = i+1; j < nums.size()-1; j++) {
                if (nums[j] > nums[i]) {
                    for (int k = j+1; k < nums.size(); k++) {
                        if (nums[k] < nums[j] && nums[k] > nums[i]) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> nums;

    nums = {1,2,3,4};
    cout << Solution().find132pattern(nums) << endl;

    nums = {3,1,4,2};
    cout << Solution().find132pattern(nums) << endl;

    nums = {-1,3,2,0};
    cout << Solution().find132pattern(nums) << endl;

    nums = {3,5,0,3,4};
    cout << Solution().find132pattern(nums) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
