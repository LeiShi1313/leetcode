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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        rec(res, 0, nums);
        return res;
    }
private:
    void rec(vector<vector<int>> &res, int i, vector<int> nums) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++) {
            if (k != i && nums[k] == nums[i]) continue;
            swap(nums[i], nums[k]);
            rec(res, i+1, nums);
        }
    }
};

int main() {
    vector<int> nums;

    nums = {1,1,2};
    cout << Solution().permuteUnique(nums) << endl;

    nums = {1,1,1};
    cout << Solution().permuteUnique(nums) << endl;

    nums = {1,2,3,4};
    cout << Solution().permuteUnique(nums) << endl;

    return 0;
}
