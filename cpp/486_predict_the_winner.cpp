//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() % 2 == 0) return true;

        vector<vector<int>> mem(nums.size(), vector<int>(nums.size(), 0));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int best = searchMax(nums, mem, 0, nums.size()-1);
        return 2*best >= sum;
    }

private:
    int searchMax(vector<int> &nums, vector<vector<int>> &mem, int i, int j) {
        if (i > j) return 0;
        if (mem[i][j]) return mem[i][j];

        int a = nums[i] + min(searchMax(nums, mem, i+1, j-1), searchMax(nums, mem, i+2, j));
        int b = nums[j] + min(searchMax(nums, mem, i, j-2), searchMax(nums, mem, i+1, j-1));
        mem[i][j] = max(a, b);

        return mem[i][j];
    }
};

int main() {
    vector<int> nums;

    nums = {1};
    cout << Solution().PredictTheWinner(nums) << endl;

    nums = {1, 5, 2};
    cout << Solution().PredictTheWinner(nums) << endl;

    nums = {1, 5, 233, 7};
    cout << Solution().PredictTheWinner(nums) << endl;
    return 0;
}
