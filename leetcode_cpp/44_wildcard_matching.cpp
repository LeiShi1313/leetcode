//
// Created by Dicky Shi on 6/13/17.
//
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
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> opt(m+1, vector<bool>(n+1, false));

        opt[0][0] = true;
        for (int i = 1; i <= m; i++) {
            opt[i][0] = false;
        }
        for (int j = 1; j <= n; j++) {
            opt[0][j] = p[j-1] == '*' && opt[0][j-1];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    opt[i][j] = opt[i][j-1]
                            || opt[i-1][j];
                } else {
                    opt[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?')
                            && opt[i-1][j-1];
                }
            }
        }
        return opt[m][n];
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().isMatch("aa", "a") << " 0" << endl;
    cout << Solution().isMatch("aa", "aa") << " 1" << endl;
    cout << Solution().isMatch("aaa", "aa") << " 0" << endl;
    cout << Solution().isMatch("aa", "a*") << " 1" << endl;
    cout << Solution().isMatch("aa", "*") << " 1" << endl;
    cout << Solution().isMatch("aa", "?*") << " 1" << endl;
    cout << Solution().isMatch("aab", "c*a*b") << " 0" << endl;
    cout << Solution().isMatch("zacabz", "*a?b*") << " 0" << endl;
    cout << Solution().isMatch("", "*") << " 1" << endl;
    cout << Solution().isMatch("c", "*?*") << " 1" << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
