#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "utils.h"
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int n1 = nums[n-1]*nums[n-2]*nums[n-3];
        int n2 = nums[0]*nums[1]*nums[n-1];
        return n1>n2?n1:n2;
    }
};

int main() {
    vector<int> nums;

    nums = {1,2,3};
    cout << Solution().maximumProduct(nums) << " 6" << endl;
    nums = {1,2,3,4};
    cout << Solution().maximumProduct(nums) << " 24" << endl;
    nums = {-1,2,3,-4};
    cout << Solution().maximumProduct(nums) << " 12" << endl;
}
