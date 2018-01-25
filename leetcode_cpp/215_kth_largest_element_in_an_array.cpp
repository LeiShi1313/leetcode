//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0, end = nums.size() - 1;
        k = nums.size() - k;
        while (true) {
            int p = partition(nums, start, end);
            if (p == k) return nums[p];
            else if (p > k) end = p-1;
            else start = p + 1;
        }
    }

private:
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        if (nums[i+1] > pivot) {
            swap(nums[i+1], nums[end]);
        }

        return i+1;
    }
};
int main() {

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;

    return 0;
}
