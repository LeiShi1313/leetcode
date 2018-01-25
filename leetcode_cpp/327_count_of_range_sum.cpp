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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> m;
        long long sum = 0;
        int count = 0;
        m.insert(0);
        for (auto &num : nums) {
            sum += num;
            auto lower_bound = m.lower_bound(sum-upper);
            auto upper_bound = m.upper_bound(sum-lower);
            count += distance(lower_bound, upper_bound);
            m.insert(sum);
        }

        return count;
    }
};

int main() {
    vector<int> nums;

    nums = {-2, 5, -1};
    cout << Solution().countRangeSum(nums, -2, 2) << endl;


    return 0;
}
