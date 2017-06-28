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
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int> num_map;
        for (auto &num: nums) {
            num_map[num]++;
            if (num_map[num] > nums.size()/2) {
                return num;
            }
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
