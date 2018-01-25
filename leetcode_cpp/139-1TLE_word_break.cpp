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
        return rec(s, wordDict, 0);

    }

    bool rec(string& s, vector<string>& wordDict, int i) {
        if (i >= s.length()) return true;
        for (int j = 1; i+j <= s.length(); j++) {
            string tmp = s.substr(i, j);
            auto it = find(wordDict.begin(), wordDict.end(), tmp);
            if (it != wordDict.end()) {
                if (rec(s, wordDict, i+j)) {
                    return true;
                }
            }
        }
        return false;
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
