//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> mem(t.length()+1, vector<int>(s.length()+1, 0));


        for (int i = 0; i <= s.length(); i++) {
            mem[0][i] = 1;
        }

        for (int i = 1; i <= t.length(); i++) {
            for (int j = 1; j<= s.length(); j++) {
                if (t[i-1] == s[j-1]) {
                    mem[i][j] = mem[i-1][j-1] + mem[i][j-1];
                } else {
                    mem[i][j] = mem[i][j-1];
                }
            }
        }

        return mem[t.length()][s.length()];
    }
};

int main() {

    string s1, s2;

    s1 = "rabbbit";
    s2 = "rabbit";
    cout << Solution().numDistinct(s1, s2) << endl;

    s1 = "axxbbc";
    s2 = "abc";
    cout << Solution().numDistinct(s1, s2) << endl;


    return 0;
}
