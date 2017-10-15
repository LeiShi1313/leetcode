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
        vector<int> flagCol(n, 1), flag45(2*n-1, 1), flag135(2*n-1, 1);
        _solveQueens(ret, nQueens, flagCol, flag45, flag135, 0, n);
        return ret;
    }
private:
    void _solveQueens(vector<vector<string>>& ret, vector<string>& nQueens,
                      vector<int>& flagCol, vector<int>& flag45, vector<int>& flag135,
                      int row, int n) {
        if (row == n) {
            ret.push_back(nQueens);
            return;
        }

        for (int col = 0; col != n; col++) {
            if (flagCol[col] && flag45[col+row] && flag135[n-1+col-row]) {
                flagCol[col] = flag45[col+row] = flag135[n-1+col-row] = 0;
                nQueens[row][col] = 'Q';
                _solveQueens(ret, nQueens, flagCol, flag45, flag135, row+1, n);
                nQueens[row][col] = '.';
                flagCol[col] = flag45[col+row] = flag135[n-1+col-row] = 1;
            }

        }
    }

};

int main() {

    cout << Solution().solveNQueens(5) << endl;
    return 0;
}
