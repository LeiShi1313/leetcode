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
    int romanToInt(string s) {
        map<char, int> roman_chart = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int result = roman_chart[s.back()];
        for (int i = s.size()-2; i >= 0; --i) {
            if (roman_chart[s[i]] >= roman_chart[s[i+1]]) {
                result += roman_chart[s[i]];
            } else {
                result -= roman_chart[s[i]];
            }
        }
        return result;
    }
};
int main() {
//    clock_t start = clock();
    cout << Solution().romanToInt("MCMIV") << "-1904" << endl;
    cout << Solution().romanToInt("MCMLIV") << "-1954" << endl;
    cout << Solution().romanToInt("MCMXC") << "-1990" << endl;
    cout << Solution().romanToInt("MMXIV") << "-2014" << endl;
    cout << Solution().romanToInt("MCMIV") << "-1904" << endl;
    cout << Solution().romanToInt("MCMIV") << "-1904" << endl;
    cout << Solution().romanToInt("MCMIV") << "-1904" << endl;
    cout << Solution().romanToInt("MCMIV") << "-1904" << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
