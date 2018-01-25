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
    int arrayPairSum(vector<int>& nums) {
        vector<int> ht(20001, 0);
        bool f = true;

        for (auto &num: nums) {
            ht[num+10000]++;
        }

        int res = 0;
        for (int i = 0; i < 20001; ) {
            if (ht[i] > 0 && f) {
                res += i-10000;
                f = false;
                ht[i]--;
            } else if (ht[i] > 0 && !f) {
                ht[i]--;
                f = true;
            } else {
                i++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums;

    nums = {1,4,2,3};
    cout << Solution().arrayPairSum(nums) << endl;



    return 0;
}
