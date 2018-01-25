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
        int z = x^y;
        z = z - ((z >> 1) & 0x55555555);
        z = (z & 0x33333333) + ((z >> 2) & 0x33333333);
        return (((z + (z >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
};

int main() {

    cout << Solution().hammingDistance(10, 11) << endl;
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
