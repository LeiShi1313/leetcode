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
        vector<vector<int>> res;
        vector<int> v;
        unordered_map<int, int> m;
        for (auto &num: nums) {
            m[num]++;
        }
        backTrace(res, v, m, nums, nums.size());
        return res;
    }
private:
    void backTrace(vector<vector<int>> &res, vector<int> &v,
                   unordered_map<int, int> &m, vector<int> &nums, int c) {
        if (c == 0) {
            res.push_back(v);
            return;
        }

        for (auto &item: m) {
            if (item.second == 0) {
                continue;
            }
            item.second--;
            v.push_back(item.first);
            backTrace(res, v, m, nums, c-1);
            v.pop_back();
            item.second++;
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
