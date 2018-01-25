//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

int guess(int num) {
    if (num > 6) {
        return -1;
    } else if (num < 6) {
        return 1;
    } else {
        return 0;
    }
}

class Solution {
public:
    int guessNumber(int n) {

        int low = 1, high = n;
        int mid, response;

        while (true) {
            mid = low + (high-low)/2;
            response = guess(mid);
            if (response == 0) {
                return mid;
            } else if (response == 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

    }
};

int main() {

    cout << Solution().guessNumber(10) << endl;
    return 0;
}
