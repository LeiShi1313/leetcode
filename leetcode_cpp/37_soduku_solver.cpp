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
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }

private:
    bool solveSudoku(vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solveSudoku(board, i+1, 0);
        if (board[i][j] != '.') return solveSudoku(board, i, j+1);

        for (char c='1'; c<='9'; ++c) {
            if (isvalid(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    bool isvalid(vector<vector<char> > &board, int i, int j, char c) {
        for (int row = 0; row < 9; ++row) {
            if (board[row][j] == c)
                return false;
        }
        for (int col = 0; col < 9; ++col) {
            if (board[i][col] == c)
                return false;
        }
        int row = i - i%3;
        int col = j - j%3;
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (board[row+x][col+y] == c) {
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
    Solution().solveSudoku(board);
    cout << board << endl;
//    clock_t end = clock();
//    cout << "Time used: " << end - start << endl;
    return 0;
}
