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
        if (mem.count(s)) return mem[s];

        vector<string> ret;
        if ()
        return ret;
    }
private:
    unordered_map<string, vector<string>> mem;

    vector<string> combine(string word, vector<string> prev) {
        return prev;
    }

};

int main() {

    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}
