#include<iostream>
#include <vector>
#include "utils.h"
using namespace std;



class Solution {
public:
    // O(logn^2), don't like the solution
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int res = 0, t;
        int sign = (dividend>0 ^ divisor>0) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while (dvd >= dvs) {
            long long tmp = dvs;
            t = 1;
            tmp <<= 1;
            while (dvd >= tmp) {
                tmp <<= 1;
                t <<= 1;
            }
            dvd -= tmp>>1;
            res += t;
        }
        return sign == 1 ? res : -res;
    }
};

int main() {
    cout << Solution().divide(15, 3) << endl;
}
