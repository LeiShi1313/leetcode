//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return nCr(m+n-2, min(m,n)-1);
    }

private:
    int nCr (int n, int r) {
        long res = 1;
        for (int i = 0; i != r; ++i) {
            res *= (n - r + 1 + i);
            res /= (i + 1);
        }
        return (int) res;
    }
};

int main() {

    cout << Solution().uniquePaths(3, 7) << endl;
    cout << Solution().uniquePaths(1, 2) << endl;
    cout << Solution().uniquePaths(1, 1) << endl;
    cout << Solution().uniquePaths(4, 4) << endl;
    cout << Solution().uniquePaths(2, 100) << endl;

    return 0;
}
