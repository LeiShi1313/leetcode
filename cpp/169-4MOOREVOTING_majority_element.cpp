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
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            } else {
                counts += (nums[i] == major) ? 1 : -1;
            }
        }
        return major;
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
