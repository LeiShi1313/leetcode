//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        bitset<3> flag(0);

        while (num != 1 && flag.count() != 3) {
            if (!flag.test(0)) {
                if (num % 2 == 0) {
                    num /= 2;
                } else {
                    flag |= 1;
                }
            }
            if (!flag.test(1)) {
                if (num % 3 == 0) {
                    num /= 3;
                } else {
                    flag |= 2;
                }
            }
            if (!flag.test(2)) {
                if (num % 5 == 0) {
                    num /= 5;
                } else {
                    flag |= 4;
                }
            }
        }

        return num == 1;
    }
};

int main() {

    cout << Solution().isUgly(1) << endl;
    cout << Solution().isUgly(6) << endl;
    cout << Solution().isUgly(8) << endl;
    cout << Solution().isUgly(14) << endl;
    cout << Solution().isUgly(25) << endl;
    cout << Solution().isUgly(17) << endl;

    return 0;
}
