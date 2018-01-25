//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int i= 0, j = 0;
        while (j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
                if (i >= s.size()) return true;
            } else {
                j++;
            }
        }
        return false;
    }
};

int main() {
    cout << Solution().isSubsequence("", "ahbgdc") << endl;

    cout << Solution().isSubsequence("abc", "ahbgdc") << endl;

    cout << Solution().isSubsequence("axc", "ahbgdc") << endl;

    cout << Solution().isSubsequence("ace", "abcde") << endl;

    cout << Solution().isSubsequence("aec", "abcde") << endl;
    return 0;
}
