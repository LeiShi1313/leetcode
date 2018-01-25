//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        bool inLeft = true;
        int num = 1;
        string numStr = "";
        int left = 0;
        int right = 0;

        for (int i = 0; i < equation.size();i++) {
            if (equation[i] >= '0' && equation[i] <= '9') {
                numStr += equation[i];
                continue;
            } else {
                if (equation[i] == 'x') {
                    num *= (numStr.empty() ? 1 : stoi(numStr));
                    left += num;
                    num = inLeft ? 1 : -1;
                    numStr = "";
                    continue;
                } else {
                    if (!numStr.empty()) {
                        num *= stoi(numStr);
                        right -= num;
                        num = inLeft ? 1 : -1;
                        numStr = "";
                    }

                    if (equation[i] == '+') {
                        num *= 1;
                    } else if (equation[i] == '-') {
                        num *= -1;
                    } else if (equation[i] == '=') {
                        inLeft = false;
                        num = -1;
                    }
                }
            }
        }
        if (!numStr.empty()) {
            num *= stoi(numStr);
            right -= num;
        }
        if (left == 0) {
            if (right == 0) return "Infinite solutions";
            else return "No solution";
        } else {
            return "x=" + to_string(right / left);
        }
    }
};

int main() {

    cout << Solution().solveEquation("x+5-3+x=6+x-2") << endl;
    cout << Solution().solveEquation("x=x") << endl;
    cout << Solution().solveEquation("2x=x") << endl;
    cout << Solution().solveEquation("2x+3x-6x=x+2") << endl;
    cout << Solution().solveEquation("x=x+2") << endl;

    return 0;
}
