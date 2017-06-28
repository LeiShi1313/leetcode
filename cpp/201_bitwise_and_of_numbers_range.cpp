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
    int rangeBitwiseAnd(int m, int n) {
        int count=0;
        while (m!=n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().rangeBitwiseAnd(5,7) << endl;
    cout << Solution().rangeBitwiseAnd(1,15) << endl;
    cout << Solution().rangeBitwiseAnd(1,1) << endl;
    cout << Solution().rangeBitwiseAnd(1,1024) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
