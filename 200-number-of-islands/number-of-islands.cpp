class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<bool> > &visited,int x,int y){
        // pair<row,col>
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        visited[x][y] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            if(row > 0 && grid[row-1][col] == '1' && visited[row-1][col] == false){
                visited[row-1][col] = true;
                q.push(make_pair(row-1,col));
            }
            // if(row>0 && col> 0 && grid[row-1][col-1] == '1' && visited[row-1][col-1] == false){
            //     visited[row-1][col-1] = true;
            //     q.push(make_pair(row-1,col-1));
            // }
            // if(row>0 && col < grid[row].size()-1 && grid[row-1][col+1] == '1' && visited[row-1][col+1] == false){
            //     visited[row-1][col+1] = true;
            //     q.push(make_pair(row-1,col+1));
            // }
            if(col < grid[row].size()-1 && grid[row][col+1] == '1' && visited[row][col+1] == false){
                visited[row][col+1] = true;
                q.push(make_pair(row,col+1));
            }
            // if(row<grid.size()-1 && col<grid[row].size()-1 && grid[row+1][col+1] == '1' && visited[row+1][col+1] == false){
            //     visited[row+1][col+1] = true;
            //     q.push(make_pair(row+1,col+1));
            // }
            if(row<grid.size()-1 && grid[row+1][col] == '1' && visited[row+1][col] == false){
                visited[row+1][col] = true;
                q.push(make_pair(row+1,col));
            }
            // if(row<grid.size()-1 && col > 0 && grid[row+1][col-1] == '1' && visited[row+1][col-1] == false){
            //     visited[row+1][col-1] = true;
            //     q.push(make_pair(row+1,col-1));
            // }
            if(col > 0 && grid[row][col-1] == '1' && visited[row][col-1] == false){
                visited[row][col-1] = true;
                q.push(make_pair(row,col-1));
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    ans++;
                    solve(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};