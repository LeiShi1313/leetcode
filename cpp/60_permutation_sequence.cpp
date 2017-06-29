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
    string getPermutation(int n, int k) {
        int i, j, f = 1;
        string s = "";
        for (i = 1; i <= n; i++) {
            f *= i;
            s += '0'+i;
        }
        for (i=0,k--; i<n; i++) {
            f /= n-i;
            j = i + k/f;
            char c = s[j];
            for (; j > i; j--) {
                s[j] = s[j-1];
            }
            s[i] = c;
            k %= f;
        }
        return s;
    }

};

int main() {
//    clock_t start = clock();
    cout << Solution().getPermutation(4, 14) << endl;
    cout << Solution().getPermutation(1, 1) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
