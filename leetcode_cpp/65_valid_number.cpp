#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <algorithm>
#include <functional>
#include <numeric>
#include "utils.h"
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        int i = 0, j = s.length()-1;
        while (s[i] == ' ') i++;
        while (s[j] == ' ') j--;
        bool haveNum = false;
        for (; i <= j; i++) {
            //cout << s[i] << ' ' << state;
            if (s[i] >= '0' && s[i] <= '9') {
                haveNum = true;
                switch (state) {
                    case 0:
                    case 1:
                    case 2:
                        state = 2;
                        break;
                    case 3:
                    case 4:
                        state = 4;
                        break;
                    case 5:
                    case 6:
                    case 7:
                        state = 7;
                        break;
                    default:
                        return false;
                }
            } else if (s[i] == '.') {
                if (state == 0 || state == 1 || state == 2) state = 3;
                else return false;
            } else if (s[i] == '+' || s[i] == '-') {
                if (!state) state = 1;
                else if (state == 5) state = 6;
                else return false;
            } else if (s[i] == 'e') {
                if (state == 2 || (haveNum && state == 3) || state == 4) state = 5;
                else return false;
            } else {
                return false;
            }
            //cout << ' ' << state << endl;
         }
        return state == 2 || state == 4 || state == 7 || (haveNum && state == 3);
    }
};

void test(int index, string input, bool res) {
    cout << index << ' ' << Solution().isNumber(input) << "<===>" << res << endl;
}

int main() {
    test(1, "123", true);
    test(2, " 123 ", true);
    test(3, "0", true);
    test(4, "0123", true);  //Cannot agree
    test(5, "00", true);  //Cannot agree
    test(6, "-10", true);
    test(7, "-0", true);
    test(8, "123.5", true);
    test(9, "123.000000", true);
    test(10, "-500.777", true);
    test(11, "0.0000001", true);
    test(12, "0.00000", true);
    test(13, "0.", true);  //Cannot be more disagree!!!
    test(14, "00.5", true);  //Strongly cannot agree
    test(15, "123e1", true);
    test(16, "1.23e10", true);
    test(17, "0.5e-10", true);
    test(18, "1.0e4.5", false);
    test(19, "0.5e04", true);
    test(20, "12 3", false);
    test(21, "1a3", false);
    test(22, "", false);
    test(23, "     ", false);
    test(24, NULL, false);
    test(25, ".1", true); //Ok, if you say so
    test(26, ".", false);
    test(27, "2e0", true);  //Really?!
    test(28, "+.8", true);
    test(29, " 005047e+6", true);  //Damn = =|||


    return 0;
}
