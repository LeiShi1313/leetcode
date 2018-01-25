//
// Created by Dicky Shi on 6/7/17.
//
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i,j;
        int start=0, len=1;
        int OPT[s.size()][s.size()];

        for (i = 0; i < s.size(); i++) {
            OPT[i][i] = 1;
            if (i < s.size()-1) {
                if (s[i]==s[i+1]) {
                    OPT[i][i+1] = 2;
                    start = i;
                    len = 2;
                }
                else
                    OPT[i][i+1] = 1;
            }
        }

        for (int gap = 2; gap < s.size(); gap++) {
            for (i = 0; i < s.size()-gap; i++) {
                j = i + gap;

                if (s[i] == s[j] && OPT[i+1][j-1] == gap-1) {
                    OPT[i][j] = OPT[i+1][j-1] + 2;
                    start = i;
                    len = OPT[i+1][j-1] + 2;
                } else {
                    OPT[i][j] = 0;
                }
            }
        }
        return s.substr(start, len);
    }
};

int main() {
    cout << Solution().longestPalindrome("babadada");
    return 0;
}