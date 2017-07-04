//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int n = INT_MIN;
        stack<int> s;
        for (int i = nums.size()-1; i >= 0; i++) {
            if (nums[i] < n) return true;
            else {
                while (!s.empty() && nums[i] > s.top()) {
                    n = s.top(); s.pop();
                }
                s.push(nums[i]);
            }
        }
        return false;
    }
};

int main() {
//    clock_t start = clock();
    vector<int> nums;

    nums = {1,2,3,4};
    cout << Solution().find132pattern(nums) << endl;

    nums = {3,1,4,2};
    cout << Solution().find132pattern(nums) << endl;

    nums = {-1,3,2,0};
    cout << Solution().find132pattern(nums) << endl;

    nums = {3,5,0,3,4};
    cout << Solution().find132pattern(nums) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
