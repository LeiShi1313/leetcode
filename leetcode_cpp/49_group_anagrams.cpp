//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mem;

        for (auto& str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            mem[s].push_back(str);
        }

        vector<vector<string>> ret;
        for (auto &k: mem) {
            ret.push_back(k.second);
        }
        return ret;
    }
};

int main() {

    vector<string> strs;

    strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << Solution().groupAnagrams(strs) << endl;

    return 0;
}
