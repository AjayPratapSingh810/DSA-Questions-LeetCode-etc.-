class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<bool> > visited(rows,vector<bool> (cols,false));
        queue<pair<int,pair<int,int> > > q;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    q.push(make_pair(0,make_pair(i,j)));
                }else{
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while(!q.empty()){
            pair<int,pair<int,int> > p = q.front();
            q.pop();
            int price = p.first;
            int row = p.second.first;
            int col = p.second.second;
            // up
            if(row > 0 && mat[row-1][col] != 0){
                if(mat[row-1][col] > price+1){
                    mat[row-1][col] = price+1;
                    q.push(make_pair(price+1,make_pair(row-1,col)));
                }
            }
            // down
            if(row < rows-1 && mat[row+1][col] != 0){
                if(mat[row+1][col] > price+1){
                    mat[row+1][col] = price+1;
                    q.push(make_pair(price+1,make_pair(row+1,col)));
                }
            }
            // left
            if(col > 0 && mat[row][col-1] != 0){
                if(mat[row][col-1] > price+1){
                    mat[row][col-1] = price+1;
                    q.push(make_pair(price+1,make_pair(row,col-1)));
                }
            }
            // right
            if(col < cols-1 && mat[row][col+1] != 0){
                if(mat[row][col+1] > price+1){
                    mat[row][col+1] = price+1;
                    q.push(make_pair(price+1,make_pair(row,col+1)));
                }
            }
        }
        return mat;
    }
};