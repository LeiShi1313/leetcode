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
    double myPow(double x, int n) {
        if (n == 0) return 1;
        unsigned long long p;
        if (n < 0) {
            p = -n;
            x = 1/x;
        } else {
            p = n;
        }
        double ans = 1;
        while (p) {
            if (p & 1) {
                ans *= x;
            }
            x *= x;
            p >>= 1;
        }
        return ans;
    }

};

int main() {

    cout << Solution().myPow(8.88023, 3) << endl;
    return 0;
}
