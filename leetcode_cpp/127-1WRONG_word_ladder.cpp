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
        int endIdx = -2;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                endIdx = i;
                break;
            }
        }
        if (endIdx == -2) return 0;
        wordList.erase(wordList.begin()+endIdx);
        wordSize = beginWord.size();
        checkAndInsert(beginWord, -1, 0, 0);
        if (checkAndInsert(endWord, endIdx, -1, endIdx) == 2) {
            return 2;
        }

        auto it = find(wordList.begin(), wordList.end(), beginWord);
        if (it != wordList.end()) {
            wordList.erase(it);
        }
        int longest = 0;
        unordered_set<int> enRoute = {};
        search(-1, endIdx, wordList, longest, enRoute);

        return longest;
    }
private:
    unordered_map<string, unordered_set<int>> mem;
    int wordSize;

    void search(int lastIdx, int endIdx, vector<string>& wordList,
                int &longest, unordered_set<int>& enRoute) {
        for (int i = 0; i < wordList.size(); i++) {
            if (enRoute.find(i) == enRoute.end()) {
                int ret = checkAndInsert(wordList[i], i, lastIdx, endIdx);
                if (ret == 1){
                    enRoute.insert(i);
                    search(i, endIdx, wordList, longest, enRoute);
                    enRoute.erase(i);
                } else if (ret == 2) {
                    enRoute.insert(i);
                    if (longest == 0 || enRoute.size()+2 < longest) {
                        longest = enRoute.size()+2;
                    }
                    enRoute.erase(i);
                    return;
                }
            }
        }
    }

    int checkAndInsert(string word, int idx, int lastIdx, int endIdx) {
        int i;
        string tmp = "";
        int ret = 0;
        vector<string> subWord;
        for (i = 0; i < wordSize; i++) {
            if (i > 0 && i < wordSize - 1) {
                tmp = word.substr(0, i) + word.substr(i+1);
            } else if (i == 0) {
                tmp = word.substr(1);
            } else {
                tmp = word.substr(0, wordSize-1);
            }
            subWord.push_back(tmp);
            mem[tmp].insert(idx);
        }
        for (auto &w: subWord) {
            auto it = mem.find(w);
            if ((*it).second.find(lastIdx) != (*it).second.end()) {
                ret = ret < 1 ? 1 : ret;
            }
        }
        if (ret == 1) {
            for (auto &w: subWord) {
                auto it = mem.find(w);
                if ((*it).second.find(endIdx) != (*it).second.end()) {
                    ret = ret == 1 ? 2 : ret;
                }
            }
        }
        return ret;
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
