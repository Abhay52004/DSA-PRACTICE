// Problem: Rat in a Maze
// Find all unique paths that a rat can take from position (0, 0) to position (N - 1, N - 1)
// in an N x N square matrix. Cells with 0 are blocked, and cells with 1 are open.
// Uses recursive backtracking with path accumulation and a visited tracker.

#include <iostream>
#include <vector> 
#include <string>

using namespace std;

// Helper function to check if the rat can move to board[row][col].
// A move is valid if the position is within boundary, not blocked, and not visited yet.
bool ispossible(int row, int col, int n, vector<vector<int>> &maze, vector<vector<int>> &visited){
    if(row >= 0 && row < n && col >= 0 && col < n && maze[row][col] != 0 && visited[row][col] == 0) {
        return true;
    }
    return false;
}

// Recursive backtracking function to find all paths.
// Parameters:
// - row, col: Current cell coordinates.
// - n: Size of the maze.
// - curr: Path string built so far (e.g. "DDR").
// - str: Vector to store all the valid paths found.
// - maze: The input maze grid.
// - visited: Tracking grid to prevent revisiting cells in the current path.
void solve(int row, int col, int n, string curr, vector<string> &str, vector<vector<int>> &maze, vector<vector<int>> &visited){
    // Base Case: If the rat reaches the destination, save the path.
    if(row == n - 1 && col == n - 1){
        str.push_back(curr);
        return;
    }
    
    // Mark the current cell as visited
    visited[row][col] = 1;
    
    // Direction 1: Down (D)
    if(ispossible(row + 1, col, n, maze, visited)){
        solve(row + 1, col, n, curr + 'D', str, maze, visited);
    }
    // Direction 2: Up (U)
    if(ispossible(row - 1, col, n, maze, visited)){
        solve(row - 1, col, n, curr + 'U', str, maze, visited);
    }
    // Direction 3: Left (L)
    if(ispossible(row, col - 1, n, maze, visited)){
        solve(row, col - 1, n, curr + 'L', str, maze, visited);
    }
    // Direction 4: Right (R)
    if(ispossible(row, col + 1, n, maze, visited)){
        solve(row, col + 1, n, curr + 'R', str, maze, visited);
    }
    
    // Backtrack: Unmark current cell so it can be visited in alternative paths
    visited[row][col] = 0; 
}

int main(){
    int n;
    cout << "Enter the size of the maze (N): ";
    cin >> n;
    
    cout << "Enter the maze cells (0 for blocked, 1 for open):" << endl;
    vector<vector<int>> maze(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }
    }
   
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> str;
    string curr = "";
    
    // Start search if the entry cell itself is not blocked
    if (maze[0][0] != 0) {
        solve(0, 0, n, curr, str, maze, visited);
    }
    
    cout << "\nAll possible paths to reach destination (D=Down, U=Up, L=Left, R=Right):" << endl;
    if (str.empty()) {
        cout << "No path exists!" << endl;
    } else {
        for (const string& path : str) {
            cout << path << "\n";
        }
    }
    
    return 0;
}