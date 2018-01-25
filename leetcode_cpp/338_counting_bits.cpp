//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> nums(num+1, 0);

        for (int i = 1; i <= num; ++i) {
            nums[i] = nums[i&(i-1)] + 1;
        }
        return nums;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().countBits(1) << endl;
    cout << Solution().countBits(2) << endl;
    cout << Solution().countBits(3) << endl;
    cout << Solution().countBits(4) << endl;
    cout << Solution().countBits(5) << endl;
    cout << Solution().countBits(8) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
