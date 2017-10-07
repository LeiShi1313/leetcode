#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int z = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            z ^= nums[i];
        }
        return z;
    }
};

int main() {
    vector<int> nums;

    nums = {1,1,2,2,3,4,3};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}
