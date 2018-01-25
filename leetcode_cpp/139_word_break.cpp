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
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> mem(s.size()+1, false);
        mem[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (mem[j]) {
                    string tmp = s.substr(j, i-j);
                    if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                        mem[i] = true;
                        break;
                    }
                }
            }
        }

        return mem[s.size()];

    }


};

int main() {

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << Solution().wordBreak(s, wordDict) << endl;

    s = "bb";
    wordDict = {"a", "b", "bbb", "bbbb"};
    cout << Solution().wordBreak(s, wordDict) << endl;

    s = "leettcode";
    wordDict = {"leet", "code"};
    cout << Solution().wordBreak(s, wordDict) << endl;

    s = "leetcode";
    wordDict = {"lee", "code"};
    cout << Solution().wordBreak(s, wordDict) << endl;

    s = "leetcde";
    wordDict = {"leet", "code"};
    cout << Solution().wordBreak(s, wordDict) << endl;

    return 0;
}
