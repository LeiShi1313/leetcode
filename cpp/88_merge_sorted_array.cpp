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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1, j = n-1, k = m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] <= nums2[j]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k--] = nums1[i--];
            }
        }

        while (i >= 0) {nums1[k--] = nums1[i--];}
        while (j >= 0) {nums1[k--] = nums2[j--];}

        return;
    }
};

int main() {

    vector<int> nums1;
    vector<int> nums2;

    nums1 = {2,4,6,0,0,0};
    nums2 = {3,5,7};
    Solution().merge(nums1, 3, nums2, 3);
    cout << nums1 << endl;

    nums1 = {1,2,3,0,0,0};
    nums2 = {2,5,6};
    Solution().merge(nums1, 3, nums2, 3);
    cout << nums1 << endl;
    return 0;
}
