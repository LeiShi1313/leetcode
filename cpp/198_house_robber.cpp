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
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() < 2) return nums[0];
        vector<int> mem(nums.size()+1);

        mem[0] = nums[0];
        mem[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            mem[i] = max(i-3>=0?mem[i-3]+nums[i]:0, i-2>=0?mem[i-2]+nums[i]:0);
        }
        return max(mem[nums.size()-1], mem[nums.size()-2]);
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,3,4,6,23,21,2,65,1};
    cout << Solution().rob(nums) << endl;

    return 0;

};
