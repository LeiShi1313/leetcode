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

        vector<int> mem(s.length()+1, 0);
        mem[0] = 1;
        mem[1] = s[0] != '0' ? 1 : 0;

        for (int i = 2; i <= s.length(); i++) {
            string s_of_2 = s.substr(i-2, 2);
            if (s[i-1] >= '1' && s[i-1] <= '9')
                mem[i] += mem[i-1];
            if (stoi(s_of_2) > 9 && stoi(s_of_2) < 27)
                mem[i] += mem[i-2];
        }

        return mem[s.length()];
    }
};

int main() {

    cout << Solution().numDecodings("12") << endl;
    cout << Solution().numDecodings("10") << endl;
    cout << Solution().numDecodings("102") << endl;
    cout << Solution().numDecodings("111") << endl;
    return 0;
}
