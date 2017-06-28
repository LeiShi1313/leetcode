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
    int hammingWeight(uint32_t n) {

        uint32_t bit = 1;
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n & bit) != 0) {
                ++count;
            }
            bit <<= 1;
        }
        return count;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().hammingWeight(1) << endl;
    cout << Solution().hammingWeight(2) << endl;
    cout << Solution().hammingWeight(3) << endl;
    cout << Solution().hammingWeight(4) << endl;
    cout << Solution().hammingWeight(5) << endl;
    cout << Solution().hammingWeight(8) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
