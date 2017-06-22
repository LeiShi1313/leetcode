//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

class Solution {
public:

    void rec(vector<string> &v, string s, int n, int m) {
        if (n == 0 && m == 0) {
            v.push_back(s);
            return;
        }
        if (n > 0) {
            rec(v, s+"(", n-1, m+1);
        }
        if (m > 0) {
            rec(v, s+")", n, m-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        rec(v, "", n, 0);
        return v;
    }
};

int main() {
    cout << Solution().generateParenthesis(1) << endl;
    cout << Solution().generateParenthesis(2) << endl;
    cout << Solution().generateParenthesis(3) << endl;
    cout << Solution().generateParenthesis(4) << endl;

    return 0;
}
