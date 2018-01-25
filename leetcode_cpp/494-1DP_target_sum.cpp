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

    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> values;
        values[0] = 1;
        for (auto& num: nums) {
            unordered_map<int, int> tmp;
            for (auto& v: values) {
                tmp[v.first+num] += v.second;
                tmp[v.first-num] += v.second;
            }
            values = tmp;
        }
        return values[S];
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
