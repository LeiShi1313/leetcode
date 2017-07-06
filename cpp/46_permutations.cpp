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
    // Permutation II without check dup would solve
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        rec(res, v, nums);
        return res;
    }
private:
    void rec(vector<vector<int>> &res, vector<int> &v, vector<int> &nums) {
        if (v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        for (int k = 0; k < nums.size(); k++) {
            if (find(v.begin(), v.end(), nums[k]) != v.end()) continue;
            v.push_back(nums[k]);
            rec(res, v, nums);
            v.pop_back();
        }
    }
    void rec2(vector<vector<int>> &res, int i, vector<int> nums) {
        if (i == nums.size()-1) {
            res.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[j], nums[i]);
            rec2(res, i+1, nums);
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
