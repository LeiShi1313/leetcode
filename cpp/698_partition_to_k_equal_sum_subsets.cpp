#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = getSum(nums);
        if (sum % k != 0) return false;
        int pSum = sum / k;

        bitset<10000> map;
        while (true) {
            int preSize = map.count();
            unordered_map<int, int> mem;
            for (int i = 0; i < nums.size(); i++) {
                if (map.test(i)) continue;
                if (nums[i] == pSum) map.set(i);
                else if (nums[i] > pSum) return false;
                if (mem.find(nums[i]) == mem.end()) {
                    for (auto& it: mem) {
                        if (nums[i] < it.first) {
                            mem[it.first-nums[i]] = i;
                        }
                    }
                    mem[pSum-nums[i]] = i;
                } else {
                    map.set(i);
                    map.set(mem[nums[i]]);
                    mem.erase(nums[i]);
                    int tmp = nums[i] + nums[mem[nums[i]]];
                    while (tmp < pSum) {
                        tmp += nums[mem[tmp]];
                        map.set(mem[tmp]);
                        mem.erase(mem[tmp]);
                    }
                }
            }
            if (map.count() == nums.size()) break;
            if (map.count() == preSize) return false;
        }
        return true;
    }
private:
    int getSum(vector<int>& nums) {
        int sum = 0;
        for (auto& num: nums) {
            sum += num;
        }
        return sum;
    }
};
int main() {
    vector<int> v = {4,3,2,3,5,2,1};
    cout << Solution().canPartitionKSubsets(v, 4) << endl;

    v = {7628, 3147, 7137, 2578, 7742, 2746, 4264, 7704, 9532, 9679, 8963, 3223, 2133, 7792, 5911, 3979};
    cout << Solution().canPartitionKSubsets(v, 6) << endl;

    v = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << Solution().canPartitionKSubsets(v, 1) << endl;
    return 0;
}
