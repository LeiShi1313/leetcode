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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        unordered_map<int, int> cnt;
        for (auto& num: nums) {
            cnt[num]++;
        }
        for (auto &it: cnt) {
            pq.push(make_pair(it.second, it.first));
            while (pq.size() > k) pq.pop();
        }
        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

int main() {
    vector<int> nums;

    nums = {1,1,1,2,2,3};
    cout << Solution().topKFrequent(nums, 2) << endl;

    return 0;
}
