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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(ret, cur, 0, nums);
        return ret;
    }
private:
    void dfs(vector<vector<int>> &ret, vector<int> &cur, int idx, const vector<int> &nums) {
        if (idx == nums.size()) {
            ret.push_back(cur);
            return;
        }

        dfs(ret, cur, idx+1, nums);
        cur.push_back(nums[idx]);
        dfs(ret, cur, idx+1, nums);
        cur.pop_back();
    }
};

int main() {
//    clock_t start = clock();
    vector<int> nums = {1,2,3};
    cout << Solution().subsetsWithDup(nums) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
