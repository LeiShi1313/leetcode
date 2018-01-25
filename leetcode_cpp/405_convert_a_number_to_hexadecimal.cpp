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
    string toHex(int num) {
        if (num == 0) return "0";
        string HEX = "0123456789abcdef";
        string s = "";
        int count = 0;
        while (num && count++ < 8) {
            s = HEX[(num & 0xf)] + s;
            num >>= 4;
        }
        return s;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().toHex(7) << endl;
    cout << Solution().toHex(15) << endl;
    cout << Solution().toHex(-1) << endl;
    cout << Solution().toHex(-2) << endl;
    cout << Solution().toHex(1024) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
