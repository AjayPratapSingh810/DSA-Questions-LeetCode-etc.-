class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool> > mp(rows,vector<bool> (cols,false));

        queue<pair<int,int> > q;

        for(int i= 0;i<rows;i++){
            for(int j= 0;j<cols;j++){
                if((i == 0 || j == 0 || i==rows-1 || j==cols-1) && grid[i][j]==1){
                    q.push(make_pair(i,j));
                    mp[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if(row > 0 && grid[row-1][col] == 1 && mp[row-1][col] == false){
                mp[row-1][col] = true;
                q.push(make_pair(row-1,col));
            }
            if(row<rows-1 && grid[row+1][col] == 1 && mp[row+1][col] == false){
                mp[row+1][col] = true;
                q.push(make_pair(row+1,col));
            }
            if(col > 0 && grid[row][col-1] == 1 && mp[row][col-1] == false){
                mp[row][col-1] = true;
                q.push(make_pair(row,col-1));
            }
            if(col < cols-1 && grid[row][col+1] == 1 && mp[row][col+1] == false){
                mp[row][col+1] = true;
                q.push(make_pair(row,col+1));
            }
        }
        int ans = 0;
        for(int i= 0;i<rows;i++){
            for(int j= 0;j<cols;j++){
                if(grid[i][j] == 1 && mp[i][j]== false){
                    ans++;
                }
            }
        }
        return ans;
    }
};