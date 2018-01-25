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
    string smallestGoodBase (string n) {
        unsigned long long num = (unsigned long long)stoll(n);
        unsigned long long x = 1;
        int maxLen = log(num)/log(2)+1;
        for (int i = maxLen; i >= 1; --i) {
            if ((x << i) < num) {
                unsigned long long cur = helper(num, i);
                if (cur != 0) return to_string(cur);
            }
        }
        return to_string(num-1);
    }
private:
    unsigned long long helper(unsigned long long n, int d) {
        double num = (double) n;
        unsigned long long right = (unsigned long long)(pow(num, 1.0/d)+1);
        unsigned long long left = 1;

        while (left <= right) {
            unsigned long long mid = left + (right-left) / 2;
            unsigned long long sum = 1, cur = 1;
            for (int i = 1; i <= d; i++) {
                cur *= mid;
                sum += cur;
            }
            if (sum == n) return mid;
            if (sum > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 0;
    }
};

int main() {

    cout << Solution().smallestGoodBase("13") << endl;
    cout << Solution().smallestGoodBase("4681") << endl;
    cout << Solution().smallestGoodBase("821424692950225218") << endl;
    cout << Solution().smallestGoodBase("100000000000000") << endl;

    return 0;
}
