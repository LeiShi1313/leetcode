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
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (((1 + maxChoosableInteger) * maxChoosableInteger / 2) < desiredTotal) return false;
        unordered_map<int, bool> mem;

        return search(mem, 0, maxChoosableInteger, desiredTotal);
    }

private:
    bool search(unordered_map<int, bool> &mem, int used, int &maxInt, int total) {
        if (mem[used]) return mem[used];

        for (int i = 1; i <= maxInt; i++) {
            int mask = 1 << i;
            if ((mask & used) == 0 && (i >= total || !search(mem, mask|used, maxInt, total-i))) {
                return mem[used] = true;
            }
        }
        return mem[used] = false;
    }
};

int main() {

    cout << Solution().canIWin(10, 11) << endl;
    cout << Solution().canIWin(20, 300) << endl;
    return 0;
}
