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
    void sortColors(vector<int>& nums) {

        int ptr_2 = nums.size()-1;
        int ptr_0 = 0;
        int i = 0;
        while (i <= ptr_2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr_0++]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[ptr_2--]);
                continue;
            }
            i++;
        }

    }
};

int main() {
    vector<int> nums;

    nums = {1,2};
    Solution().sortColors(nums);
    cout << nums << endl;

    nums = {2,1};
    Solution().sortColors(nums);
    cout << nums << endl;

    nums = {1,0};
    Solution().sortColors(nums);
    cout << nums << endl;

    nums = {0,1};
    Solution().sortColors(nums);
    cout << nums << endl;

    nums = {1,2,0};
    Solution().sortColors(nums);
    cout << nums << endl;

    nums = {1,0,1,2,0,0,1,2,1,1,0};
    Solution().sortColors(nums);
    cout << nums << endl;
    return 0;
}
