class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int size = grid.size();
        if (grid[0][0] != 0 || grid[size - 1][size - 1] != 0) {
            return -1;
        }
        vector<vector<bool>> visited(size, vector<bool>(size, false));
        queue<pair<pair<int, int>,int>> q;
        q.push(make_pair(make_pair(0,0), 0));
        int n = size;
        while (!q.empty()) {
            pair<pair<int, int>,int> pr = q.front();
            pair<int,int> p = pr.first;
            int x = pr.second;
            q.pop();
            int row = p.first;
            int col = p.second;
            if(row == size-1 && col == size-1){
                return x+1;
            }
            if (row > 0 && grid[row - 1][col] == 0 && !visited[row - 1][col]) {
                visited[row - 1][col] = true;
                q.push(make_pair(make_pair(row-1,col),x+1));
            }
            if (row < n - 1 && grid[row + 1][col] == 0 &&
                !visited[row + 1][col]) {
                visited[row + 1][col] = true;
                q.push(make_pair(make_pair(row+1,col),x+1));
            }
            if (col > 0 && grid[row][col - 1] == 0 && !visited[row][col - 1]) {
                visited[row][col - 1] = true;
               q.push(make_pair(make_pair(row,col-1),x+1));
            }
            if (col < n - 1 && grid[row][col + 1] == 0 &&
                !visited[row][col + 1]) {
                visited[row][col + 1] = true;
                q.push(make_pair(make_pair(row,col+1),x+1));
            }
            if (row > 0 && col > 0 && grid[row - 1][col - 1] == 0 &&
                !visited[row - 1][col - 1]) {
                visited[row - 1][col - 1] = true;
                q.push(make_pair(make_pair(row-1,col-1),x+1));
            }
            if (row > 0 && col < n - 1 && grid[row - 1][col + 1] == 0 &&
                !visited[row - 1][col + 1]) {
                visited[row - 1][col + 1] = true;
                q.push(make_pair(make_pair(row-1,col+1),x+1));
            }
            if (row < n - 1 && col > 0 && grid[row + 1][col - 1] == 0 &&
                !visited[row + 1][col - 1]) {
                visited[row + 1][col - 1] = true;
                q.push(make_pair(make_pair(row+1,col-1),x+1));
            }
            if (row < n - 1 && col < n - 1 && grid[row + 1][col + 1] == 0 &&
                !visited[row + 1][col + 1]) {
                visited[row + 1][col + 1] = true;
                q.push(make_pair(make_pair(row+1,col+1),x+1));
            }
        }
        if (ans == INT_MAX) {
            return -1;
        }
        return ans + 1;
    }
};