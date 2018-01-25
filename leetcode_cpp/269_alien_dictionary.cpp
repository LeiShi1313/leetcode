#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {

        unordered_map<char, unordered_set<char>> suc, pre;
        set<char> chars;
        string preWord;
        for (auto& word: words) {
            chars.insert(word.begin(), word.end());
            for (int i = 0; i < min(preWord.size(), word.size()); i++) {
                if (word[i] != preWord[i]) {
                    suc[preWord[i]].insert(word[i]);
                    pre[word[i]].insert(preWord[i]);
                    break;
                }
            }
            preWord = word;
        }

        set<char> free = chars;
        for (auto& p: pre) {
            free.erase(p.first);
        }
        string ret;

        while (!free.empty()) {
            char a = *begin(free);
            free.erase(a);
            ret += a;
            for (auto& c: suc[a]) {
                pre[c].erase(a);
                if (pre[c].empty()){
                    free.insert(c);
                }
            }
        }
        return ret.size() == chars.size() ? ret : "";
    }


};

int main() {
    vector<string> words;

    words = {
            "wrt",
            "wrf",
            "er",
            "ett",
            "rftt"
    };
    cout << Solution().alienOrder(words) << endl;

    words = {
            "z",
            "x"
    };
    cout << Solution().alienOrder(words) << endl;

    words = {
            "z",
            "x",
            "z"
    };
    cout << Solution().alienOrder(words) << endl;

    words = {
            "zy",
            "zx"
    };
    cout << Solution().alienOrder(words) << endl;

    words = {
            "z",
            "z"
    };
    cout << Solution().alienOrder(words) << endl;

    words = {
            "ac",
            "ab",
            "b"
    };
    cout << Solution().alienOrder(words) << endl;

    words = {
            "ri","xz","qxf","jhsguaw","dztqrbwbm","dhdqfb","jdv","fcgfsilnb","ooby"
    };
    cout << Solution().alienOrder(words) << endl;
    return 0;
}
