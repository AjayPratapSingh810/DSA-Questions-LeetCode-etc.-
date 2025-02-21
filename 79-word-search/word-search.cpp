class Solution {
public:
    bool solve(int row,int col,vector<vector<char> > &board,string word,int x,vector<vector<bool> > &visited){
        if(x >= word.size()){
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();
        // up
        if(row>0 && !visited[row-1][col] && board[row-1][col] == word[x]){
            visited[row-1][col] = true;
            bool ans = solve(row-1,col,board,word,x+1,visited);
            if(ans){
                return true;
            }
        }
        // down
        
        if(row< rows-1 && !visited[row+1][col] && board[row+1][col] == word[x]){
            visited[row+1][col] = true;
            bool ans = solve(row+1,col,board,word,x+1,visited);
            if(ans){
                return true;
            }
        }
        // left
        
        if(col > 0 && !visited[row][col-1] && board[row][col-1] == word[x]){
            visited[row][col-1] = true;
            bool ans = solve(row,col-1,board,word,x+1,visited);
            if(ans){
                return true;
            }
        }
        // right
        
        if(col < cols-1 && !visited[row][col+1] && board[row][col+1] == word[x]){
            visited[row][col+1] = true;
            bool ans = solve(row,col+1,board,word,x+1,visited);
            if(ans){
                return true;
            }
        }
        visited[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                vector<vector<bool> > visited(rows,vector<bool> (cols,false));
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    bool ans = solve(i,j,board,word,1,visited);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};