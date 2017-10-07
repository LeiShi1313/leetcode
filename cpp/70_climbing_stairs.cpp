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
    int climbStairs(int n) {

        int mem[n+1];
        mem[0] = 1;
        mem[1] = 1;
        for (int i = 2; i <= n; i++) {
            // To i you can either take 1 step from i-1 or 2 steps from i-2
            mem[i] = mem[i-1] + mem[i-2];
        }
        return mem[n];

    }
};

int main() {

    cout << Solution().climbStairs(2) << endl;
    cout << Solution().climbStairs(10) << endl;

    return 0;

};
