//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    int numTrees(int n) {

        int mem[n+1];
        mem[0] = mem[1] = 1;
        for (int i = 2; i <=n; i++) {
            mem[i] = 0;
            for (int j = 1; j <= i; j++) {
                mem[i] += mem[j-1] * mem[i-j];
            }
        }
        return mem[n];
    }
};

int main() {

    cout << Solution().numTrees(10) << endl;
    return 0;
}
