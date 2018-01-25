//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture[0].size(), n = picture.size();
        vector<int> rowSum(n, 0);
        vector<int> columnSum(m, 0);
        // use pair of vector to store B's location
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B') {
                    columnSum[j]++;
                    rowSum[i]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B' && rowSum[i] == 1 && columnSum[j] == 1)
                    count++;
            }
        }

        return count;
    }
};

int main() {

    vector<vector<char>> picture;

    picture = {
            {'W', 'W', 'B'},
            {'W', 'B', 'W'},
            {'B', 'W', 'W'}
    };
    cout << Solution().findLonelyPixel(picture) << endl;


    picture = {
            {'W', 'B', 'B'},
            {'W', 'B', 'W'},
            {'B', 'W', 'W'}
    };
    cout << Solution().findLonelyPixel(picture) << endl;

    return 0;
}
