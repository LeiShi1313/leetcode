//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int level;
        long long base = 9;
        int digit, nth;
        long long upperBound = 9, lowerBound = 0;
        for (level = 1; level < 10; level++) {
            if (n <= upperBound) {
                break;
            }
            base *= 10;
            lowerBound = upperBound;
            upperBound += base*(level+1);
        }
        base /= 9;
        digit = (n-lowerBound-1) / level + base;
        nth = (n-lowerBound-1) % level;

        return to_string(digit)[nth]-'0';
    }
};

int main() {

    cout << Solution().findNthDigit(3) << endl;
    cout << Solution().findNthDigit(9) << endl;
    cout << Solution().findNthDigit(10) << endl;
    cout << Solution().findNthDigit(11) << endl;
    cout << Solution().findNthDigit(12) << endl;
    cout << Solution().findNthDigit(13) << endl;
    cout << Solution().findNthDigit(14) << endl;
    cout << Solution().findNthDigit(15) << endl;
    cout << Solution().findNthDigit(189) << endl;
    cout << Solution().findNthDigit(190) << endl;
    cout << Solution().findNthDigit(2889) << endl;
    cout << Solution().findNthDigit(2990) << endl;
    cout << Solution().findNthDigit(1000000000) << endl;

    return 0;
}
