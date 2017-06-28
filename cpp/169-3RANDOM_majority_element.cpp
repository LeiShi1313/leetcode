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

        int n = nums.size();
        srand(unsigned(time(NULL)));

        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0;
            for (auto &num: nums) {
                if (num == candidate)
                    counts++;
            }
            if (counts > n / 2) return candidate;
        }
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
