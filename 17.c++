// Problem: N-Queens Problem
// The N-Queens problem requires placing N chess queens on an N x N chessboard 
// such that no two queens attack each other (no two queens share the same row, column, or diagonal).
// Uses recursive backtracking, placing queens column by column.

#include<iostream>
using namespace std;

// Helper function to check if placing a queen at board[row][col] is safe.
// Since we place queens column by column from left to right, we only need
// to check for conflicts on the left side (already placed queens).
bool ispossible(int row , int col, int n, int board[20][20]){
    int durow = row;
    int ducol = col;
    
    // Check upper-left diagonal
    while(row >= 0 && col >= 0 ){
        if(board[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    
    row = durow;
    col = ducol;
    // Check same row to the left
    while(col >= 0 ){
        if(board[row][col] == 1) {
            return false;
        }
        col--;
    }
    
    row = durow;
    col = ducol;
    // Check lower-left diagonal
    while(row < n && col >= 0 ){
        if(board[row][col] == 1) {
            return false;
        }
        row++;
        col--;
    }
    
    return true; // Safe to place queen
}

// Recursive function to solve the N-Queens board configuration
// Parameters:
// - col: The current column where we are trying to place a queen.
// - n: Total size of the board (N x N).
// - board: The 2D array representing the board.
void solve(int col , int n , int board[20][20]){
    // Base Case: If we have successfully placed queens in all N columns, print the board.
    if(col == n){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    // Try placing a queen in every row of the current column
    for(int row = 0 ; row < n; row++){
        if(ispossible(row, col, n, board)){
            // Place the queen
            board[row][col] = 1;
            
            // Recurse to place queens in the remaining columns
            solve(col + 1 , n , board);
            
            // Backtrack: Remove the queen from the current cell for other combinations
            board[row][col] = 0; 
        }
    } 
}

int main(){
    int board[20][20] = {0}; // Initialize board with all 0s
    int n;
    cout << "Enter the board size (N): ";
    cin >> n;
    
    if(n > 20 || n <= 0) {
        cout << "Error: N must be between 1 and 20." << endl;
        return 0;
    }
    
    cout << "\nAll possible valid board configurations:\n" << endl;
    solve(0, n, board);
    
    return 0;
}