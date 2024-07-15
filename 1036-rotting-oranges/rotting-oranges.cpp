class Solution {
public:
    void solve(vector<vector<int>>& grid, int& ans, int i, int j) {
        bool happen = false;
        // up
        if (i > 0) {
            if (grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                happen = true;
            }
        }
        // left
        if (j > 0) {
            if (grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                happen = true;
            }
        }
        // down
        if (i < grid.size() - 1) {
            if (grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                happen = true;
            }
        }
        // right
        if (j < grid[i].size() - 1) {
            if (grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                happen = true;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> gridCopy = grid;
        bool happen = true;
        while (happen) {
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 2) {
                        solve(gridCopy, ans, i, j);
                    }
                }
            }
            if (gridCopy != grid) {
                grid = gridCopy;
                ans++;
            }else{
                happen = false;
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};