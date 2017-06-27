//
// Created by Dicky Shi on 6/13/17.
//
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "utils.h"
using namespace std;

class Solution {
public:
    void initializeMap(vector<map<int, int> > &m) {
        for (int i = 0; i < 9; ++i) {
            map<int, int> tmp;
            for (int j = 0; j < 9; ++j) {
                tmp[j] = 0;
            }
            m.push_back(tmp);
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<int, int> > row_map;
        initializeMap(row_map);
        vector<map<int, int> > col_map;
        initializeMap(col_map);
        vector<map<int, int> > block_map;
        initializeMap(block_map);

        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                } else if (board[i][j] >= '0' && board[i][j] <= '9'){
                    // for row
                    if (!row_map[i][board[i][j]-'0']) {
                        row_map[i][board[i][j]-'0'] = 1;
                    } else {
                        return false;
                    }
                    // for col
                    if (!col_map[j][board[i][j]-'0']) {
                        col_map[j][board[i][j]-'0'] = 1;
                    } else {
                        return false;
                    }
                    //for block
                    if (!block_map[(i/3)*3+(j/3)][board[i][j]-'0']) {
                        block_map[(i/3)*3+(j/3)][board[i][j]-'0'] = 1;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
         }
        return true;
    }
};

int main() {
//    clock_t start = clock();
    vector<string> _board = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
    };
    vector<vector<char> > board = string_to_vector_of_char(_board);
    cout << Solution().isValidSudoku(board) << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
