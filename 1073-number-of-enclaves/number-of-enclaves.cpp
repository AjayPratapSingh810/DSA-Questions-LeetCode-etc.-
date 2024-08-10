class Solution {
public:
    void markBoundaryConnected(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            
            if (x > 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
                q.push(make_pair(x - 1, y));
                visited[x - 1][y] = true;
            }
            if (x < m - 1 && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
                q.push(make_pair(x + 1, y));
                visited[x + 1][y] = true;
            }
            if (y > 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
                q.push(make_pair(x, y - 1));
                visited[x][y - 1] = true;
            }
            if (y < n - 1 && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
                q.push(make_pair(x, y + 1));
                visited[x][y + 1] = true;
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Mark all boundary-connected land cells
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                markBoundaryConnected(i, 0, m, n, grid, visited);
            }
            if (grid[i][n - 1] == 1 && !visited[i][n - 1]) {
                markBoundaryConnected(i, n - 1, m, n, grid, visited);
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && !visited[0][j]) {
                markBoundaryConnected(0, j, m, n, grid, visited);
            }
            if (grid[m - 1][j] == 1 && !visited[m - 1][j]) {
                markBoundaryConnected(m - 1, j, m, n, grid, visited);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};