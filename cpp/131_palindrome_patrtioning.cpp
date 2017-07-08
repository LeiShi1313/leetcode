//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty()) return res;
        vector<string> cur;

        rec(0, s, cur, res);
        return res;
    }

private:
    void rec(int idx, string &s, vector<string> &cur, vector<vector<string>> &res) {
        if (idx == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalidrome(s, idx, i)) {
                cur.push_back(s.substr(idx, i-idx+1));
                rec(i+1, s, cur, res);
                cur.pop_back();
            }
        }
    }

    bool isPalidrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    cout << Solution().partition("aab") << endl;

    return 0;
}
