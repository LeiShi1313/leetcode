//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include "utils.h"
using namespace std;

class Solution {
public:
    void rec(vector<string> &v, string digits, string s) {
        if (digits == "") {
            v.push_back(s);
            return;
        }
        map<int, string> phone = {
                {1, ""},
                {2, "abc"},
                {3, "def"},
                {4, "ghi"},
                {5, "jkl"},
                {6, "mno"},
                {7, "pqrs"},
                {8, "tuv"},
                {9, "wxyz"}
        };
        for (int i = 0; i < phone[digits[0]-'0'].size(); ++i) {
            rec(v, digits.substr(1, digits.size()-1), s+phone[digits[0]-'0'][i]);
        }
    }
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        if (digits == "") return vector<string>();
        rec(res, digits, "");
        return res;
    }
};

int main() {
    cout << Solution().letterCombinations("") << endl;
    cout << Solution().letterCombinations("23") << endl;
    cout << Solution().letterCombinations("456") << endl;
    cout << Solution().letterCombinations("345") << endl;
    cout << Solution().letterCombinations("123") << endl;

    return 0;
}
