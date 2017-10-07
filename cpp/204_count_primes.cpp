#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
#include "utils.h"
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool mem[n];
        memset(mem, true, sizeof(bool) * (n));
        int count = 0;

        for (int i = 3; i < n; i++) {
            if (i % 2 == 0) mem[i] = false;
        }
        for (int i = 3; i <= sqrt(n); i++) {
            if (mem[i]) {
                for (int j = 2; i*j < n; j++) {
                    mem[i*j] = false;
                }
            }
        }

        for (int i = 2; i < n; i++) {
            if (mem[i]) count++;
        }
        return count;

    }

};

int main() {

    cout << Solution().countPrimes(10) << endl;
    cout << Solution().countPrimes(100) << endl;
    return 0;
}
