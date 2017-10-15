#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (j+1 < n && nums[j]==nums[j+1]) j++;
                    j++;
                    while (k-1 >= i+1 && nums[k]==nums[k-1]) k--;
                    k--;
                } else if (sum < 0) {
                    while (j+1 < n && nums[j]==nums[j+1]) j++;
                    j++;
                } else {
                    while (k-1 >= i+1 && nums[k]==nums[k-1]) k--;
                    k--;
                }
            }
        }
        return ret;
    }
};
int main() {
    vector<int> nums;

    nums = {-1, 0, 1, 2, -1, -4};
    cout << Solution().threeSum(nums) << endl;

    nums = {0, 0, 0, 0};
    cout << Solution().threeSum(nums) << endl;

    nums = {-1, -1, 0 ,1};
    cout << Solution().threeSum(nums) << endl;

    return 0;
}
