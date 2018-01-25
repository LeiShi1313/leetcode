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
        int count = 0;

        while (n) {
            n &= (n - 1);
            count++;
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
