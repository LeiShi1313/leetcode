//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {

        int len = words.size();
        int dis = len-1;
        int f = -1;
        bool same = word1 == word2;

        for (int i = 0; i < len; i++) {
            if (words[i] == word1 || words[i] == word2) {
                if (f != -1) {
                    if (same || words[i] != words[f]) {
                        dis = min(dis, abs(i - f));
                    }
                }
                f = i;
            }
        }

        return dis;
    }
};

int main() {

    string word1 = "practice";
    string word2 = "coding";
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    cout << Solution().shortestDistance(words, word1, word2) << endl;

    word1 = "makes";
    word2 = "makes";
    words = {"practice", "makes", "perfect", "coding", "makes"};
    cout << Solution().shortestDistance(words, word1, word2) << endl;

    word1 = "a";
    word2 = "b";
    words = {"a", "a", "c", "b"};
    cout << Solution().shortestDistance(words, word1, word2) << endl;

    return 0;
}
