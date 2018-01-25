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
    int getSum(int a, int b) {
        int sum = a;
        while (b) {
            sum = a ^ b;
            b = (a&b) << 1;
            a = sum;
        }
        return sum;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().getSum(1,78) << endl;
    cout << Solution().getSum(INT_MAX,1) << endl;
    cout << Solution().getSum(-1,1) << endl;
    cout << Solution().getSum(INT_MIN,-1) << endl;
    cout << Solution().getSum(-1,-1) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
