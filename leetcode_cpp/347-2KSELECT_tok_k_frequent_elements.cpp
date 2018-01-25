#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <queue>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> cnt;
        for (auto &num: nums) cnt[num]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &kv: cnt) {
            bucket[kv.second].push_back(kv.first);
        }
        for (int i = bucket.size()-1; i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                ret.push_back(bucket[i][j]);
                if (ret.size() == k) return ret;
            }
        }
        return ret;
    }
};

int main() {
    vector<int> nums;

    nums = {1,1,1,2,2,3};
    cout << Solution().topKFrequent(nums, 2) << endl;

    nums = {3,2,2,1,1,1};
    cout << Solution().topKFrequent(nums, 2) << endl;

    return 0;
}
