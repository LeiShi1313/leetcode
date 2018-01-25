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
    int mySqrt(int x) {
        long long r = x;
        while (r * r > x) {
            r = (r + x/r) / 2;
        }
        return r;
    }
};

void test(int input, int res) {
    cout << Solution().mySqrt(input) << "===" << res << endl;
}

int main() {

    test(0, 0);
    test(1, 1);
    test(4, 2);
    test(7, 2);
    test(9, 3);
    test(16, 4);
    test(17, 4);
    test(36, 6);
    test(81, 9);
    test(80, 8);
    test(82, 9);

    return 0;

};
