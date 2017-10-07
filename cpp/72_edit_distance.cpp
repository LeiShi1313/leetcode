#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> dis(word2.size()+1, vector<int>(word1.size()+1, 0));

        for (int i = 1; i <= word1.size(); i++) {
            dis[0][i] = i;
        }
        for (int i = 1; i <= word2.size(); i++) {
            dis[i][0] = i;
        }

        for (int i = 1; i <= word2.size(); i++) {
            for (int j = 1; j <= word1.size(); j++) {
                if (word1[j-1] == word2[i-1]) {
                    dis[i][j] = dis[i-1][j-1];
                } else {
                    dis[i][j] = min(min(dis[i-1][j], dis[i][j-1]), dis[i-1][j-1])+1;
                }
            }
        }
        return dis[word2.size()][word1.size()];
    }
};

int main() {

    string word1, word2;

    word1 = "word";
    word2 = "wrd";
    cout << Solution().minDistance(word1, word2) << endl;

    word1 = "word";
    word2 = "ward";
    cout << Solution().minDistance(word1, word2) << endl;




    return 0;
}
