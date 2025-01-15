#include <iostream> 
#include <vector> 
using namespace std; 
 
bool isSafe(vector<int>& board, int row, int col, int n) {     
    for (int i = 0; i < row; ++i) { 
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {             
            return false; 
        }     }     
        return true; 
} 
 
void solveNQueens(int row, int n, vector<int>& board, int& count) {     
    if (row == n) {         
        ++count;         
        return; 
    } 
    for (int col = 0; col < n; ++col) {         
        if (isSafe(board, row, col, n)) {             
            board[row] = col; 
            solveNQueens(row + 1, n, board, count);            
             board[row] = -1; 
        } 
    } 
} 
 
int totalNQueens(int n) {     
    vector<int> board(n, -1);     
    int count = 0; 
    solveNQueens(0, n, board, count);     
    return count; 
} 
 
int main() {     
    int n; 
    cout << "Enter the value of n: ";     
    cin >> n; 
 
    int result = totalNQueens(n); 
    cout << "Number of distinct solutions: " << result << endl;     
    return 0; 
}
