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
        set<long long> m;
        int j;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                m.erase(nums[i-k-1]);
            }

            auto it = m.lower_bound((long long)nums[i]-t);
            if (it != m.end() && llabs(*it-nums[i]) <= t)  {
                return true;
            }

            m.insert((long long)nums[i]);
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

    nums = {0,10,22,15,0,5,22,12,1,5};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 3, 3) << endl;

    return 0;
}
