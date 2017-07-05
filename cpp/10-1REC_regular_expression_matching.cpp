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
        if (p == "") return s == "";

        // what is p[1] not exist? ---- July 4
        if (p[1] == '*') {
            return (isMatch(s, p.substr(2))
                    || !s.empty()
                       && (s[0] == p[0] || p[0] == '.')
                       && isMatch(s.substr(1), p));
        } else {
            return !s.empty()
                   && (s[0] == p[0] || p[0] == '.')
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
    cout << Solution().isMatch("aa", "a.") << " 1" << endl;
    cout << Solution().isMatch("aa", "..") << " 1" << endl;
    cout << Solution().isMatch("abc", "a*b*c*") << " 1" << endl;
    cout << Solution().isMatch("abc", "c*c*c") << " 0" << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
