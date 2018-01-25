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
        int count = 0;
        while (z) {
            z = z & (z-1);
            count++;
        }
        return count;
    }
};

int main() {

    cout << Solution().hammingDistance(10, 11) << endl;
    cout << Solution().hammingDistance(1, 4) << endl;
    return 0;
}
