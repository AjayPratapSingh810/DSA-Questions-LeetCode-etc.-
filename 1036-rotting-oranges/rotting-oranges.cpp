class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // queue<pair<row,col>>
        queue<pair<int, int>> q;
        int n = grid.size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    q.push(p);
                }
            }
        }
        pair<int, int> pr;
        pr.first = -1;
        pr.second = -1;
        q.push(pr);
        int ans = 0;
        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;
            if (x == -1 && y == -1) {
                if (!q.empty()) {
                    ans++;
                    q.push(pr);
                }
                continue;
            }
            if (x > 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                pair<int, int> p;
                p.first = x - 1;
                p.second = y;
                q.push(p);
            }

            if (x < n - 1 && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                pair<int, int> p;
                p.first = x + 1;
                p.second = y;
                q.push(p);
            }
            if (y > 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                pair<int, int> p;
                p.first = x;
                p.second = y - 1;
                q.push(p);
            }
            if (y < grid[x].size() - 1 && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                pair<int, int> p;
                p.first = x;
                p.second = y + 1;
                q.push(p);
            }
        }
         for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};