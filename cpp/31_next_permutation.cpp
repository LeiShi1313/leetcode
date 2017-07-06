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
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1])
                break;
        }
        reverse(nums.begin()+i+1, nums.end());
        if (i == -1) return;

        auto l = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
        cout << *l << endl;
        swap(nums[i], *(nums.end()-1));
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,3};
    Solution().nextPermutation(nums);
    cout << nums << endl;

    nums = {3,2,1};
    Solution().nextPermutation(nums);
    cout << nums << endl;

    nums = {1,1,5};
    Solution().nextPermutation(nums);
    cout << nums << endl;

    return 0;
}
