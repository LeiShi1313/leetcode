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
    int trap(vector<int>& height) {
        vector<int> pre(height.size()+1, 0);
        vector<int> post(height.size()+1, 0);

        for (int i = 1; i <= height.size(); i++) {
            if (height[i-1] > pre[i-1]) {
                pre[i] = height[i-1];
            } else {
                pre[i] = pre[i-1];
            }
        }

        for (int i = height.size()-1; i >= 0; i--) {
            if (height[i] > post[i+1]) {
                post[i] = height[i];
            } else {
                post[i] = post[i+1];
            }
        }
        int count = 0;
        for (int i = 1; i < pre.size(); i++) {
            count += (pre[i]>post[i-1]?post[i-1]:pre[i]) - height[i-1];
        }

        return count;
    }
};

int main() {
    vector<int> nums;

    nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(nums) << endl;

    return 0;
}
