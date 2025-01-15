#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<char>>& board, int row, int col, char num) {
    // Check if the number is already present in the row, column or 3x3 grid
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num || 
            board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = '.'; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true; // Solved
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    solveSudoku(board);
    
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    
    return 0;
}
