class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        
        q.push({r, c});
        visited[r][c] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                    grid[nr][nc] == '1' && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islandCount = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islandCount++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        
        return islandCount;
    }
};