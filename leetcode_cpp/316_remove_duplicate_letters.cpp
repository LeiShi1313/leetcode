//
// Created by Dicky Shi on 6/13/17.
//
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
    string removeDuplicateLetters(string s) {

        vector<int> cand(26, 0);
        vector<bool> visited(26, false);

        for (char &c: s) {
            cand[c-'a']++;
        }

        string ret = "0";
        for (char &c: s) {
            cand[c-'a']--;
            if (visited[c-'a']) continue;
            while (c < ret.back() && cand[ret.back()-'a']) {
                visited[ret.back()-'a'] = false;
                ret.pop_back();
            }
            ret += c;
            visited[c-'a'] = true;
        }
        return ret.substr(1);
    }
};

int main() {

    cout << Solution().removeDuplicateLetters("bcabc") << endl;

    cout << Solution().removeDuplicateLetters("cbacdcbc") << endl;

    return 0;
}
