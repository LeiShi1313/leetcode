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
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i;
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
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
