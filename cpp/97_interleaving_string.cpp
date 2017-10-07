#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;

        vector<vector<bool>> mem(s1.length()+1, vector<bool>(s2.length()+1, false));

        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) mem[i][j] = true;
                else if (i == 0) {
                    mem[i][j] = s2[j-1] == s3[j-1] ? mem[i][j-1] : false;
                } else if (j == 0) {
                    mem[i][j] = s1[i-1] == s3[i-1] ? mem[i-1][j] : false;
                } else {
                    mem[i][j] = (mem[i-1][j] && s1[i-1] == s3[i+j-1])
                                || (mem[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return mem[s1.length()][s2.length()];
    }
};

int main() {

    string s1, s2, s3;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    cout << Solution().isInterleave(s1, s2, s3) << endl;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    cout << Solution().isInterleave(s1, s2, s3) << endl;

    s1 = "aabcc";
    s2 = "adbbc";
    s3 = "aadbbcabcc";
    cout << Solution().isInterleave(s1, s2, s3) << endl;
    return 0;
}
