//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > v;
        vector<string> v0 = {""};

        v.push_back(v0);

        // f(n) = (f(0))f(n-1) + (f(1))f(n-2) + ... + (f(n-1))f(0)
        for (int i = 1; i <= n; ++i) {
            vector<string> vi;
            v.push_back(vi);
            for (int j = 0; j < i; ++j) {
                for (vector<string>::iterator it1 = v[j].begin(); it1 != v[j].end(); ++it1) {
                    for (vector<string>::iterator it2 = v[i-j-1].begin(); it2 != v[i-j-1].end(); ++it2) {
                        v[i].push_back("("+*it1+")"+*it2);
                    }
                }
            }
        }
        return v[n];
    }
};

int main() {
    cout << Solution().generateParenthesis(1) << endl;
    cout << Solution().generateParenthesis(2) << endl;
    cout << Solution().generateParenthesis(3) << endl;
    cout << Solution().generateParenthesis(4) << endl;

    return 0;
}
