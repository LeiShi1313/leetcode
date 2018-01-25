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
    vector<int> singleNumber(vector<int>& nums) {
        int first = 0;
        for (auto &num: nums) {first ^= num;};
        int diff = (first & (first-1)) ^ first;
        int intA=0, intB=0;
        for (auto &num: nums) {
            if (num & diff) {
                intA ^= num;
            } else {
                intB ^= num;
            }
        }
        return vector<int>{intA, intB};
    }
};

int main() {
    vector<int> nums;

    nums = {1, 2, 1, 3, 2, 5};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}
