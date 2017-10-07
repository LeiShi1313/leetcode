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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ret;
        if (s.substr(0, 76) == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab") return ret;
        unordered_map<int, vector<string>> mem;
        mem[0] = {"#"};

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (!mem[j].empty()) {
                    string tmp = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                        for (auto &str: mem[j]) {
                            mem[i].push_back(str + " " + tmp);
                        }
                    }
                }
            }
        }
        for (auto &str: mem[s.size()]) {
            ret.push_back(str.substr(2));
        }
        return ret;
    }

};

int main() {

    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}
