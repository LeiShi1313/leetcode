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
        vector<int> pre(n, 1);

        for (int l = 1; l < m; ++l) {
            for (int i = 1; i < n; ++i) {
                pre[i] = pre[i-1] + pre[i];
            }
        }

        return pre[n-1];
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
