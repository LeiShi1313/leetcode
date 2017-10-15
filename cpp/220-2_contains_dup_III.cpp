//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) return false;
        set<long long> map;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                map.erase(nums[i-k-1]);
            }
            long long lower = (long long)nums[i] - t;
            auto it = lower_bound(map.begin(), map.end(), lower);
            if (it != map.end() && llabs(nums[i]-*it) <= t) return true;
            map.insert((long long)nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums;

    nums = {-1,-1};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 1, 1) << endl;

    nums = {7,1,3};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 2, 3) << endl;

    nums = {4,1,-1,6,5};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 3, 1) << endl;

    nums = {-1, 2147483647};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;

    nums = {2147483647, -2147483647};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 1, 2147483647) << endl;

    nums = {-2147483648, -2147483647};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 3, 3) << endl;

    nums = {0,10,22,15,0,5,22,12,1,5};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 3, 3) << endl;

    return 0;
}
