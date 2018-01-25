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
    string nearestPalindromic(string n) {
        if (!n.length()) return n;
        if (n.length() == 1 ) {
            if (n[0] > '0') {
                n[0]--; return n;
            } else {
                return "1";
            }
        }
        int middle = (n.length()+1) / 2;
        int offset = n.length() % 2 == 0 ? 0 : -1;
        string mid = makePalindrome(n.substr(0, middle), offset);
        string smaller = makePalindrome(minusOne(n.substr(0, middle)), offset);
        string larger = makePalindrome(plusOne(n.substr(0, middle)), offset);
        string allNine = string(n.length()-1, '9');
        string oneOone = '1' + string(n.length()-1, '0') + '1';
        vector<string> candidate = {oneOone, larger, mid, smaller, allNine};
        string res;
        long long minDis = LLONG_MAX;
        for (auto& num: candidate) {
            if (num.empty()) continue;
            long long tmpDis = llabs(stoll(n) - stoll(num));
            if (tmpDis > 0 && tmpDis <= minDis) {
                minDis = tmpDis;
                res = num;
            }
        }
        return res;
    }
private:
    string minusOne(string n) {
        if (n.back() > '0') {
            n.back()--;
            if (n.length() == 1 && n[0] == '0') return "";
            return n;

        } else {
            return minusOne(n.substr(0, n.length()-1)) + '9';
        }
    }
    string plusOne(string n) {
        if (!n.length()) return "1";
        if (n.back() < '9') {
            n.back()++;
            return n;
        } else {
            return plusOne(n.substr(0, n.length()-1)) + '0';
        }
    }
    string makePalindrome(string n, int offset) {
        int i = n.length() - 1 + offset;

        for (; i >= 0; i--) {
            n += n[i];
        }
        return n;
    }
};

int main() {

    cout << Solution().nearestPalindromic("0") << endl;
    cout << Solution().nearestPalindromic("1") << endl;
    cout << Solution().nearestPalindromic("6") << endl;
    cout << Solution().nearestPalindromic("10") << endl;
    cout << Solution().nearestPalindromic("12") << endl;
    cout << Solution().nearestPalindromic("19") << endl;
    cout << Solution().nearestPalindromic("99") << endl;
    cout << Solution().nearestPalindromic("23456") << endl;

    return 0;
}
