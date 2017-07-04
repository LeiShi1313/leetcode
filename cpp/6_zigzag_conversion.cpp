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
    string convert(string s, int numRows) {
        if (numRows == 1 || s == "") return s;
        int line = 0;
        int n = s.size();
        int i = 0, idx = 0;
        string res = "";
        while (line < numRows) {
            i = 0;idx=line;
            while (idx < n) {
                if (line % (numRows-1) == 0) {
                    res += s[idx];
                } else {
                    res += s[idx];
                    if (2*(i+1)*(numRows-1) - line < n) {
                        res += s[2*(i+1)*(numRows-1)-line];
                    }
                }
                i++;
                idx = 2*i*(numRows-1)+line;
            }
            line++;
        }
        return res;
    }
};

int main() {
//    clock_t start = clock();
    cout << Solution().convert("PAYPALISHIRING", 3) << endl;
    cout << Solution().convert("PAYPALISHIRING", 4) << endl;
    cout << Solution().convert("PAYPALISHIRING", 2) << endl;
    cout << Solution().convert("ABCDE", 4) << endl;
    cout << Solution().convert("ABCDEF", 3) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
