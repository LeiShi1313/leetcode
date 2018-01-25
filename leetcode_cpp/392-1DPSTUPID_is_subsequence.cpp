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

        vector<vector<bool>> mem(s.size()+1, vector<bool>(t.size()+1, false));

        for (int i = 0; i <= t.size(); i++) mem[0][i] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                mem[i][j] = mem[i][j-1] ||
                        ((s[i-1] == t[j-1]) && mem[i-1][j-1]);
            }
        }
        return mem[s.size()][t.size()];
    }
};

int main() {

    cout << Solution().isSubsequence("abc", "ahbgdc") << endl;

    cout << Solution().isSubsequence("axc", "ahbgdc") << endl;

    cout << Solution().isSubsequence("ace", "abcde") << endl;

    cout << Solution().isSubsequence("aec", "abcde") << endl;
    return 0;
}
