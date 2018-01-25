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
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s;

        heights.push_back(0);

        int sum = 0;
        int i = 0;
        while (i < heights.size()) {
            if (s.empty() || heights[i] > heights[s.back()]) {
                s.push_back(i);
                i++;
            } else {
                int t = s.back();
                s.pop_back();
                sum = max(sum, heights[t] * (s.empty() ? i : i-s.back()-1));
            }
        }
        return sum;
    }
};

int main() {

    vector<int> nums;

    nums = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(nums) << endl;

    nums = {1,2,3,4,5,6};
    cout << Solution().largestRectangleArea(nums) << endl;

    nums = {2,3,2,1,2,4,3};
    cout << Solution().largestRectangleArea(nums) << endl;

    nums = {2,3,2,1,2,4,3};
    cout << Solution().largestRectangleArea(nums) << endl;
    return 0;
}
