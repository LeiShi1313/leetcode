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
        unordered_map<int, int> ht;
        int j;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                for (j = 1; j <= t; j++) {
                    ht[nums[i-k-1]+j]--;
                    if (ht[nums[i-k-1]+j] <= 0) ht.erase(nums[i-k-1]+j);
                    ht[nums[i-k-1]-j]--;
                    if (ht[nums[i-k-1]-j] <= 0) ht.erase(nums[i-k-1]-j);
                }
                ht[nums[i-k-1]]--;
                if (ht[nums[i-k-1]] <= 0) ht.erase(nums[i-k-1]);
            }
            if (ht.find(nums[i]) != ht.end()) return true;

            ht[nums[i]]++;
            for (j = 1; j <= t; j++) {
                ht[nums[i]+j]++;
                ht[nums[i]-j]++;
            }
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

    return 0;
}
