class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool> > visited(rows,vector<bool> (cols,false));
        vector<vector<char> > ans(rows,vector<char> (cols,'X'));

        queue<pair<int,int> > q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((i == 0 || j == 0 || i == rows-1 || j == cols-1) && board[i][j] == 'O'){
                    visited[i][j] = true;
                    q.push(make_pair(i,j));
                    ans[i][j] = 'O';
                }
            }
        }

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int i= p.first;
            int j= p.second;

            if(i > 0 && visited[i-1][j] == false && board[i-1][j] == 'O'){
                q.push(make_pair(i-1,j));
                visited[i-1][j] = true; 
                ans[i-1][j] = 'O';
            }
            if(j < cols-1 && visited[i][j+1] == false && board[i][j+1] == 'O'){
                q.push(make_pair(i,j+1));
                visited[i][j+1] = true;
                ans[i][j+1] = 'O'; 
            }
            if(i < rows-1 && visited[i+1][j] == false && board[i+1][j] == 'O'){
                q.push(make_pair(i+1,j));
                visited[i+1][j] = true;
                ans[i+1][j] = 'O'; 
            }
            if(j > 0 && visited[i][j-1] == false && board[i][j-1] == 'O'){
                q.push(make_pair(i,j-1));
                visited[i][j-1] = true;
                ans[i][j-1] = 'O';
            }

        }
        board =  ans;
    }
};