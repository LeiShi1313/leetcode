//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        vector<int> a(n, 1);
        vector<int> b(n, 1);

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                a[i] = b[i-1]+1;
                b[i] = b[i-1];
            } else if (nums[i] < nums[i-1]) {
                b[i] = a[i-1] + 1;
                a[i] = a[i-1];
            } else {
                b[i] = b[i-1];
                a[i] = a[i-1];
            }
        }
        return max(a[n-1], b[n-1]);
    }
};


int main() {
    vector<int> nums;

    nums = {1,7,4,9,2,5};
    cout << Solution().wiggleMaxLength(nums) << endl;

    nums = {1,17,5,10,13,15,10,5,16,8};
    cout << Solution().wiggleMaxLength(nums) << endl;

    nums = {8,16,5,10,15,13,10,5,17,1};
    cout << Solution().wiggleMaxLength(nums) << endl;

    nums = {1,2,3,4,5,6,7,8,9};
    cout << Solution().wiggleMaxLength(nums) << endl;

    nums = {0, 0};
    cout << Solution().wiggleMaxLength(nums) << endl;

    nums = {3,3,3,2,5};
    cout << Solution().wiggleMaxLength(nums) << endl;
    return 0;
}
