#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return;

        int count = 0;
        int cache[2];
        cache[0] = nums[0];
        int idx = 0;
        int base = idx;
        int idxToBe;
        while (count < n) {
            idxToBe = (idx + k) % n;
            cache[1] = nums[idxToBe];
            nums[idxToBe] = cache[0];
            cache[0] = cache[1];
            idx = idxToBe;
            count++;
            if (idxToBe == base) {
                base++;
                idx = base;
                cache[0] = nums[base];
                continue;
            }
        }
        return;
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,3,4,5,6,7};
    Solution().rotate(nums, 4);
    cout << nums << endl;

    nums = {1,2,3,4,5,6,7};
    Solution().rotate(nums, 2);
    cout << nums << endl;

    nums = {1,2,3,4,5,6};
    Solution().rotate(nums, 2);
    cout << nums << endl;

    return 0;
}
