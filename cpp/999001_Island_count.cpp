#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    int countIsland(vector<vector<int>> island) {
        int n = island.size();
        if (n < 1) return 0;
        int m = island[0].size();

        vector<vector<bool>> checked(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (checked[i][j]) continue;
                else if (island[i][j] == 0) checked[i][j] = true;
                else {
                    count++;
                    floodFill(i, j, island, checked);
                }
            }
        }
        return count;
    }
private:
    void floodFill(int i, int j, vector<vector<int>>& island, vector<vector<bool>>& checked) {
        if (island[i][j] == 0 || checked[i][j]) {checked[i][j] = true;return;}
        checked[i][j] = true;
        if (i > 0) floodFill(i-1, j, island, checked);
        if (j > 0) floodFill(i, j-1, island, checked);
        if (i < island.size()-1) floodFill(i+1, j, island, checked);
        if (j < island[0].size()-1) floodFill(i, j+1, island, checked);

    }
};
int main() {

    vector<vector<int>> matrix;

    matrix = {
            {0,1,0,1,0},
            {0,0,1,1,1},
            {1,0,0,1,0},
            {0,1,1,0,0},
            {1,0,1,0,1}
    };
    cout << Solution().countIsland(matrix) << endl;
    return 0;
}
