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
    int hammingDistance(int x, int y) {
        if (x == y) return 0;
        int diff = 0;
        int mask = 1;
        while (mask <= x || mask <= y) {
            if ((mask & x) != (mask & y)) {
                diff++;
            }
            mask <<= 1;
        }
        return diff;
    }
};

int main() {

    cout << Solution().hammingDistance(10, 11) << endl;
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
