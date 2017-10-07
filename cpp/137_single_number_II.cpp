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
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};

int main() {
    vector<int> nums;

    nums = {1,1,1,2,2,2,4};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}
