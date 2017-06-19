//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class Solution {
public:
    string repeatN(int n, char c) {
        string s;
        for (int i = 0; i < n; ++i) {
            s += c;
        }
        return s;
    }
    string intToRoman(int num) {
        map<int, char> int_roman_chart = {
                {1, 'I'},
                {5, 'V'},
                {10, 'X'},
                {50, 'L'},
                {100, 'C'},
                {500, 'D'},
                {1000, 'M'}
        };

        int carry = 1000;
        int i = 0;
        string result = "";
        while (carry) {
            i = num / carry;
            if (i > 8) {
                result += int_roman_chart[carry];
                result += int_roman_chart[carry*10];
            } else if (i > 5) {
                result += int_roman_chart[carry*5];
                result += repeatN(i-5, int_roman_chart[carry]);
            } else if (i == 5) {
                result += int_roman_chart[carry*5];
            } else if (i > 3) {
                result += int_roman_chart[carry];
                result += int_roman_chart[carry*5];
            } else if (i > 0) {
                result += repeatN(i, int_roman_chart[carry]);
            }
            num %= carry;
            carry /= 10;
        }
        return result;
    }
};
int main() {
//    clock_t start = clock();
    cout << Solution().intToRoman(1904) << "-MCMIV" << endl;
    cout << Solution().intToRoman(1954) << "-MCMLIV" << endl;
    cout << Solution().intToRoman(1990) << "-MCMXC" << endl;
    cout << Solution().intToRoman(2014) << "-MMXIV" << endl;
    cout << Solution().intToRoman(1904) << "-MCMIV" << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
