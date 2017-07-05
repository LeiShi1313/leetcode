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
        if (p.empty()) return s.empty();

        if (p[0] == '*') {
            return isMatch(s, p.substr(1))
                   || (!s.empty()
                   && isMatch(s.substr(1), p));

        } else {
            return !s.empty()
                   && (s[0] == p[0] || p[0] == '?')
                   && isMatch(s.substr(1), p.substr(1));
        }
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
