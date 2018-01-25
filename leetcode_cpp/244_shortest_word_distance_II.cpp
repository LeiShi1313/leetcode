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

class WordDistance {
public:
    WordDistance(vector<string> words) {

        for (int i = 0; i < words.size(); i++) {
            mem[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {

        vector<int> v1 = mem[word1];
        vector<int> v2 = mem[word2];

        int p1 = 0, p2 = 0;
        int dis = INT_MAX;
        while (p1 < v1.size() && p2 < v2.size()) {
            dis = min(dis, abs(v1[p1]-v2[p2]));
            v1[p1] < v2[p2] ? p1++ : p2++;
        }
        return dis;
    }

private:
    unordered_map<string, vector<int>> mem;
};

int main() {

    string word1 = "practice";
    string word2 = "coding";
    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    WordDistance obj = new WordDistance(words);
    cout << obj.shortest(word1, word2);

    return 0;
}
