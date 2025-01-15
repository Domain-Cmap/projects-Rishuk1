#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    // Check each row, column, and sub-grid
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> rowSet, colSet, subGridSet;
        for (int j = 0; j < 9; ++j) {
            // Check the row
            if (board[i][j] != '.' && rowSet.count(board[i][j])) {
                return false;
            }
            rowSet.insert(board[i][j]);

            // Check the column
            if (board[j][i] != '.' && colSet.count(board[j][i])) {
                return false;
            }
            colSet.insert(board[j][i]);

            // Check the 3x3 sub-grid
            int subRow = 3 * (i / 3);
            int subCol = 3 * (i % 3);
            char subGridVal = board[subRow + j / 3][subCol + j % 3];
            if (subGridVal != '.' && subGridSet.count(subGridVal)) {
                return false;
            }
            subGridSet.insert(subGridVal);
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '4', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '5', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}