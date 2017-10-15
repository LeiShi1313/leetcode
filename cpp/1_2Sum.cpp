#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idxs;
        unordered_map<int, int> mem;
        for (int i = 0; i < nums.size(); i++) {
            if (mem.find(nums[i]) != mem.end()) {
                return vector<int>{mem[nums[i]], i};
            } else {
                mem[target-nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};
int main() {
    vector<int> nums;

    nums = {2, 7, 11, 15};
    cout << Solution().twoSum(nums, 9) << endl;
    return 0;
}
