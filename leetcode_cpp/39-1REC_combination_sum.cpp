//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector< vector< int > > result;
        if(candidates.empty()) { return result; }

        vector< int > prefix;
        getCombinations(candidates, 0, target, prefix, result);
        return result;
    }

private:
    void getCombinations(vector< int > &nums, int startIx, int target, vector< int > &prefix, vector< vector< int > > &result)
    {
        int n = nums.size();
        if(startIx >= n)
        {
            if(target == 0) { result.push_back(prefix); }
            return;
        }

        getCombinations(nums, startIx + 1, target, prefix, result);
        if(nums[startIx] <= target)
        {
            prefix.push_back(nums[startIx]);
            getCombinations(nums, startIx, target - nums[startIx], prefix, result);
            prefix.pop_back();
        }
    }
};

int main() {
    vector<int> ints;

    ints = {2,3,6,7};
    cout << Solution().combinationSum(ints, 4) << endl;
    cout << Solution().combinationSum(ints, 7) << endl;
    cout << Solution().combinationSum(ints, 9) << endl;

    return 0;
}
