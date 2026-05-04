class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        q.push(make_pair(-1,-1));
        int ans = 0;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(p.first == -1 && p.second == -1){
                if(!q.empty()){
                    q.push(make_pair(-1,-1));
                    ans++;
                }
            }else{
                int a = p.first;
                int b = p.second;
                if(a > 0 && grid[a-1][b] == 1){
                    grid[a-1][b] = 2;
                    q.push(make_pair(a-1,b));
                }
                if(a < n-1 && grid[a+1][b] == 1){
                    grid[a+1][b] = 2;
                    q.push(make_pair(a+1,b));
                }
                if(b > 0 && grid[a][b-1] == 1){
                    grid[a][b-1] = 2;
                    q.push(make_pair(a,b-1));
                }
                if(b < m-1 && grid[a][b+1] == 1){
                    grid[a][b+1] = 2;
                    q.push(make_pair(a,b+1));
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};