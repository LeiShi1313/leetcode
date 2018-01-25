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
    vector<vector<int>> permute(vector<int>& nums) {
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

        for (int j = i; j < nums.size(); j++) {
            swap(nums[j], nums[i]);
            rec(res, i+1, nums);
        }
    }
};

int main() {
    vector<int> nums;


//    clock_t start = clock();
    nums = {1,2,3};
    cout << Solution().permute(nums) << endl;
//    clock_t end = clock();
//    cout << "Time: " << end - start << endl;

    nums = {1,2,3,4};
    cout << Solution().permute(nums) << endl;

    return 0;
}
