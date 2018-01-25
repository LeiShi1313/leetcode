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
        int start = 0, end = nums.size()-1;
        k = nums.size() - k;
        while (true) {
            int p = partition(nums, start, end);
            if (p == k) return nums[p];
            else if (p > k) end = p-1;
            else start = p+1;
        }
    }
private:
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[end];
        int storeindx = start;
        while (start < end) {
            if (nums[start] < pivot) {
                swap(nums[storeindx], nums[start]);
                storeindx++;
            }
            start++;
        }
        swap(pivot, nums[storeindx]);
        return storeindx;
    }

};
int main() {

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k) << endl;

    nums = {1};
    k = 1;
    cout << Solution().findKthLargest(nums, k) << endl;

    return 0;
}
