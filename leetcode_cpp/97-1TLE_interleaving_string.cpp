#include <iostream>
#include <vector>
#include <ctime>
#include "utils.h"
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.empty()) {
            return s1.empty() && s2.empty();
        }

        char c1 = s1.empty() ? ' ' : s1[0];
        char c2 = s2.empty() ? ' ' : s2[0];

        bool ret = false;
        if (s3[0] == c1) {
            ret = isInterleave(s1.substr(1), s2, s3.substr(1));
        }
        if (s3[0] == c2) {
            ret |= isInterleave(s1, s2.substr(1), s3.substr(1));
        }
        return ret;
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
