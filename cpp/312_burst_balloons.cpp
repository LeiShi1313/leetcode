//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> OPT(n+2, vector<int>(n+2,0));

        int i,offset,k;
        for (offset = 0; offset < n; offset++) {
            for (i = 1; i+offset <= n; i++) {
                for (k = i; k <= i+offset; k++) {
                    OPT[i][i+offset] = max(OPT[i][i+offset],
                                             OPT[i][k-1]+OPT[k+1][i+offset]+nums[i-1]*nums[k]*nums[i+offset+1]);
                }
            }
        }
        return OPT[1][n];
    }
};

int main() {
    vector<int> nums;

    nums = {3,1,5,8};
    cout << Solution().maxCoins(nums) << endl;


    return 0;
}
