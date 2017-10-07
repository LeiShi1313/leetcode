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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> cur;
        queue<string> next;

        cur.push(beginWord);
        int longest = 2;
        while (!cur.empty()) {
            string word = cur.front();
            cur.pop();
            for (auto &w: wordList) {
                if (w == "#" || !isNeighbor(word, w)) continue;
                if (w == endWord) return longest;
                next.push(w);
                w = "#";
            }
            if (cur.empty()) {
                longest++;
                swap(cur, next);
            }
        }
        return 0;
    }
private:
    bool isNeighbor(string &a, string&b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i] && ++diff > 1) return false;
        }
        return diff == 1;
    }
};

int main() {

    string beginWord = "hit";
    string endWord = "hot";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log","cog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;

    beginWord = "hot";
    endWord = "dog";
    wordList = {"hot","dog","dot"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;

    beginWord = "hot";
    endWord = "dog";
    wordList = {"hot","dog"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
