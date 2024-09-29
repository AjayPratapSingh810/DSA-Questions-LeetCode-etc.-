class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    int count = 0;
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        count++;
                        int row = p.first;
                        int col = p.second;
                        // up
                        if(row > 0 && visited[row-1][col] == false && grid[row-1][col] == 1){
                            visited[row-1][col] = true;
                            q.push(make_pair(row-1,col));
                        }
                        // right
                        if(col < n-1 && visited[row][col+1] == false && grid[row][col+1] == 1){
                            visited[row][col+1] = true;
                            q.push(make_pair(row,col+1));
                        }
                        // down
                        if(row < m-1 && visited[row+1][col] == false && grid[row+1][col] == 1){
                            visited[row+1][col] = true;
                            q.push(make_pair(row+1,col));
                        }
                        // left
                        if(col > 0 && visited[row][col-1] == false && grid[row][col-1] == 1){
                            visited[row][col-1] = true;
                            q.push(make_pair(row,col-1));
                        }
                    }
                    if(count > ans){
                        ans = count;
                    }
                }
            }
        }
        if(ans == INT_MIN){
            return 0;
        }
        return ans;
    }
};