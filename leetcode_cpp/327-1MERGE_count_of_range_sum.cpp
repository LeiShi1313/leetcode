//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        vector<long long> sums(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++) sums[i] = sums[i-1] + nums[i-1];
        return countAndMerge(sums, 1, nums.size(), lower, upper);
    }

private:
    int countAndMerge(vector<long long> &sums, int start, int end, int lower, int upper) {
        if (start > end) return 0;
        else if (start == end) return (sums[start] >= lower && sums[start] <= upper) ? 1 : 0;

        int mid = start + (end-start) / 2;

        int count = countAndMerge(sums, start, mid, lower, upper) +
                countAndMerge(sums, mid+1, end, lower, upper);
        int i, j, k;
        for (k = start, i = j = mid+1; k <= mid; k++) {
            while (i <= end && sums[i] - sums[k] < lower) i++;
            while (j <= end && sums[j] - sums[k] <= upper) j++;
            count += j - i;
        }


        i = start, j = mid+1;
        vector<long long> tmp;
        while (i <= mid && j <= end) {
            if (sums[i] < sums[j]) tmp.push_back(sums[i++]);
            else tmp.push_back(sums[j++]);
        }
        while (i <= mid) tmp.push_back(sums[i++]);
        while (j <= end) tmp.push_back(sums[j++]);

        for (i = 0; i < end-start+1; i++) {
            sums[i+start] = tmp[i];
        }
        return count;
    }
};

int main() {
    vector<int> nums;

    nums = {-2, 5, -1};
    cout << Solution().countRangeSum(nums, -2, 2) << endl;

    nums = {2147483647,-2147483648,-1,0};
    cout << Solution().countRangeSum(nums, -1, 0) << endl;


    return 0;
}
