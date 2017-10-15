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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> nQueens(n, string(n, '.'));
        _solveQueens(ret, nQueens, 0, n);
        return ret;
    }
private:
    void _solveQueens(vector<vector<string>>& ret, vector<string>& nQueens,
    int row, int n) {
        if (row == n) {
            ret.push_back(nQueens);
            return;
        }

        for (int col = 0; col != n; col++) {
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                _solveQueens(ret, nQueens, row+1, n);
                nQueens[row][col] = '.';
            }

        }
    }
    bool isValid(vector<string>& nQueens, int row, int col, int n) {
        for (int i = 0; i != row; i++) {
            if (nQueens[i][col] == 'Q') return false;
        }

        for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--) {
            if (nQueens[i][j] == 'Q') return false;
        }
        for (int i = row-1, j = col+1; i>=0 && j<n; i--, j++) {
            if (nQueens[i][j] == 'Q') return false;
        }
        return true;
    }
};

int main() {

    cout << Solution().solveNQueens(5) << endl;
    return 0;
}
