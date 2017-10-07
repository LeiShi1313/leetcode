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
    int numSquares(int n) {

        vector<int> mem(n+1, INT_MAX);

        mem[0] = 0;
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j*j <= i; j++) {
                mem[i] = min(mem[i], mem[i-j*j]+1);
            }
        }
        return mem[n];
    }
};

int main() {

    cout << Solution().numSquares(13) << endl;
    cout << Solution().numSquares(12) << endl;
    return 0;
}
