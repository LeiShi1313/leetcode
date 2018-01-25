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
    vector<int> countSmaller(vector<int>& nums) {

        vector<int> res(nums.size(), 0);
        mergeAndCount(nums, res, 0, nums.size());
        return res;
    }
private:
    // need to record the indice, too complicated
    void mergeAndCount(vector<int> &nums, vector<int> &res, int start, int end) {
        if (start == end - 1) {
            return;
        }

        int mid = (start + end) >> 1;
        mergeAndCount(nums, res, start, mid);
        mergeAndCount(nums, res, mid, end);

        int i = start, j = mid;
        while (i < mid && j < end) {
            if (i < mid && nums[i] < nums[j]) {i++;}
            else {
                res[i] += end - j;
                j++;
            }
        }

        vector<int> tmp;
        i = start, j = mid;
        while (i < mid && j < end) {
            if (nums[i] <= nums[j]) {
                tmp.push_back(nums[i++]);
            } else {
                tmp.push_back(nums[j++]);
            }
        }
        while (i < mid) {tmp.push_back(nums[i++]);}
        while (j < mid) {tmp.push_back(nums[j++]);}

        for (i = start; i < end; i++) {
            nums[i] = tmp[start-i];
        }
    }

};

int main() {
    vector<int> nums;
    vector<int> ans;

    nums = {1,1};
    ans = {0,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {5,2,5,1};
    ans = {2,1,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {5,2,6,1};
    ans = {2,1,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {5,4,3,2,1};
    ans = {4,3,2,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {1,2,3,4,5};
    ans = {0,0,0,0,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    ans = {10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0};
    cout << Solution().countSmaller(nums) << endl;
    cout << ans << endl << endl;

    return 0;
}
