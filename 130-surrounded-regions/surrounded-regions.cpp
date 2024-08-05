class Solution {
public:
void dfsVisited(vector<vector<char>>& board,vector<vector<bool> > &visited,int x,int y,int rows,int cols){
    visited[x][y] = true;
    // up
    if(x > 0){
        if(!visited[x-1][y] && board[x-1][y] == 'O'){
            dfsVisited(board,visited,x-1,y,rows,cols);
        }
    }
    if(x < rows-1){
        if(!visited[x+1][y] && board[x+1][y] == 'O'){
            dfsVisited(board,visited,x+1,y,rows,cols);
        }
    }
    if(y > 0){
        if(!visited[x][y-1] && board[x][y-1] == 'O'){
            dfsVisited(board,visited,x,y-1,rows,cols);
        }
    }
    if(y < cols-1){
        if(!visited[x][y+1] && board[x][y+1] == 'O'){
            dfsVisited(board,visited,x,y+1,rows,cols);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
         vector<vector<bool>> visited(m, vector<bool>(n, false));
        //  1st row
        for(int i=0;i<n;i++){
            if(!visited[0][i] && board[0][i] == 'O'){
                dfsVisited(board,visited,0,i,m,n);
            }
        }
        // 1st col
        for(int i=0;i<m;i++){
            if(!visited[i][0] && board[i][0] == 'O'){
                dfsVisited(board,visited,i,0,m,n);
            }
        }
        // last col
        for(int i=0;i<m;i++){
            if(!visited[i][n-1] && board[i][n-1] == 'O'){
                dfsVisited(board,visited,i,n-1,m,n);
            }
        }
        // last row
        for(int i=0;i<n;i++){
            if(!visited[m-1][i] && board[m-1][i] == 'O'){
                dfsVisited(board,visited,m-1,i,m,n);
            }
        }

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == true){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};