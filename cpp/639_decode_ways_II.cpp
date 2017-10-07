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
    int numDecodings(string s) {
        if (s.empty() || s.front() == '0') return 0;

        vector<long> mem(s.length()+1, 0);
        int p = 1000000007;
        mem[0] = 1;
        mem[1] = s[0] != '0' ? (s[0] != '*' ? 1 : 9) : 0;

        for (int i = 2; i <= s.length(); i++) {
            string s_of_2 = s.substr(i - 2, 2);
            if (s[i - 1] == '*' && s[i - 2] == '*') {
                mem[i] += 9 * mem[i - 1];
                mem[i] += 15 * mem[i - 2];
            } else if (s[i - 1] == '*') {
                mem[i] += 9 * mem[i - 1];
                if (s[i - 2] == '1') {
                    mem[i] += 9 * mem[i - 2];
                } else if (s[i - 2] == '2') {
                    mem[i] += 6 * mem[i - 2];
                }
            } else if (s[i - 2] == '*') {
                if (s[i - 1] >= '1' && s[i - 1] <= '9')
                    mem[i] += mem[i - 1];
                if (s[i - 1] > '6') {
                    mem[i] += mem[i - 2];
                } else if (s[i - 1] >= '0' && s[i - 1] < '7') {
                    mem[i] += 2 * mem[i - 2];
                }
            } else {
                if (s[i - 1] >= '1' && s[i - 1] <= '9')
                    mem[i] += mem[i - 1];
                if (stoi(s_of_2) > 9 && stoi(s_of_2) < 27)
                    mem[i] += mem[i - 2];
            }
        }

        return mem[s.length()] % p;
    }
};

int main() {

    cout << Solution().numDecodings("1*") << endl;
    cout << Solution().numDecodings("*1") << endl;
    cout << Solution().numDecodings("*") << endl;
    cout << Solution().numDecodings("11*") << endl;
    cout << Solution().numDecodings("**") << endl;
    cout << Solution().numDecodings("*1*1*0") << endl;
    cout << Solution().numDecodings("***") << endl;
    cout << Solution().numDecodings("****") << endl;
    cout << Solution().numDecodings("*****") << endl;
    cout << Solution().numDecodings("******") << endl;
    cout << Solution().numDecodings("*******") << endl;
    cout << Solution().numDecodings("********") << endl;
    cout << Solution().numDecodings("*********") << endl;
    cout << Solution().numDecodings("**********1111111111") << endl;
    return 0;
}
