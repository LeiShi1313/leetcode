//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if (n > 0) {
            int end = (n > 10) ? 10 : n; // no need to consider longer than 10 digits
            for (int i = 0; i < end; i++) {
                sum += 9 * permutation(9, i);
            }
        }
        return sum;
    }

private:
    int permutation(int n, int r) {
        if (r == 0) return 1;
        else return n * permutation(n-1, r-1);
    }
};

int main() {

    cout << Solution().countNumbersWithUniqueDigits(2) << endl;

    cout << Solution().countNumbersWithUniqueDigits(3) << endl;


    return 0;
}
