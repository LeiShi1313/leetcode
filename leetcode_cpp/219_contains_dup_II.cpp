//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) m.erase(nums[i-k-1]);
            if (m.find(nums[i]) != m.end()) {
                return true;
            }
            m.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums;

    nums = {-1,-1};
    cout << Solution().containsNearbyDuplicate(nums, 1) << endl;



    return 0;
}
