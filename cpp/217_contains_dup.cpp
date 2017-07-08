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
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> ht;
        for (auto &num: nums) {
            ht[num]++;
            if (ht[num] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums;

    nums = {1,4,2,3};
    cout << Solution().containsDuplicate(nums) << endl;



    return 0;
}
