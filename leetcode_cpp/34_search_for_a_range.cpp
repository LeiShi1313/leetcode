//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};

        int low = 0, high = nums.size()-1;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                int i = mid;
                while (i>=0 && nums[i]==target) {i--;}
                res[0] = i+1;
                for (i = mid+1; i < nums.size()&&nums[i]==target; i++) ;
                res[1] = i-1;
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums;

    nums = {5,7,7,8,8,10};
    cout << Solution().searchRange(nums, 8) << endl;
    nums = {5,7,7,8,8};
    cout << Solution().searchRange(nums, 8) << endl;
    nums = {5,7,7,8,8};
    cout << Solution().searchRange(nums, 5) << endl;
    nums = {5,5,7,7,8,8};
    cout << Solution().searchRange(nums, 5) << endl;
    nums = {5,5,7,7,8,8};
    cout << Solution().searchRange(nums, 6) << endl;
    return 0;
}
