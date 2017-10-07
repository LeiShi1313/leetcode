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
    int maxProduct(vector<int>& nums) {

        vector<int> maxP(nums.size(), 0);
        vector<int> minP(nums.size(), 0);
        maxP[0] = nums[0];
        minP[0] = nums[0];

        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxP[i] = max(max(maxP[i-1]*nums[i], nums[i]), minP[i-1]*nums[i]);
            minP[i] = min(min(minP[i-1]*nums[i], nums[i]), maxP[i-1]*nums[i]);
            ret = max(ret, maxP[i]);
        }
        return ret;
    }
};

int main() {
    vector<int> nums;

    nums = {2,3,-2,4};
    cout << Solution().maxProduct(nums) << endl;

    nums = {2,3,-2,4,-1};
    cout << Solution().maxProduct(nums) << endl;

    nums = {-2};
    cout << Solution().maxProduct(nums) << endl;

    return 0;
}
