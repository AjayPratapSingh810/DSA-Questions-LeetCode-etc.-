class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans;

        for (int i = 0; i < board.size(); i++) {
            int s = board[i].size();
            vector<int> taken(s,0);
            for (int j = 0; j < board[i].size(); j++) {
                int x = board[i][j];
                // live
                    bool liveRkhu = true;
                    int countLive = 0;
                    // ver
                    if (i > 0) {
                        if(board[i-1][j] == 1){
                            countLive++;
                        }
                    }
                    if(i<board.size()-1){
                         if(board[i+1][j] == 1){
                            countLive++;
                        }
                    }
                    //hor
                    if (j > 0) {
                        if(board[i][j-1] == 1){
                            countLive++;
                        }
                    }
                    if(j<board[i].size()-1){
                         if(board[i][j+1] == 1){
                            countLive++;
                        }
                    }
                    // diagonally
                    if(i>0 && j>0){
                        if(board[i-1][j-1] == 1){
                            countLive++;
                        }
                    }
                    if(i>0 && j<board[i].size()-1){
                        if(board[i-1][j+1] == 1){
                            countLive++;
                        }
                    }
                    if(i<board.size()-1 && j>0){
                        if(board[i+1][j-1] == 1){
                            countLive++;
                        }
                    } 
                    if(i<board.size()-1 && j<board[i].size()-1){
                        if(board[i+1][j+1] == 1){
                            countLive++;
                        }
                    }
                    if(x==1 && countLive >= 2 && countLive<=3){
                        taken[j] =1;
                    }

                    if(x == 0){
                        if(countLive == 3){
                            taken[j] = 1;
                        }
                    }            
            }
            ans.push_back(taken);
        }
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                int a = ans[i][j];
                board[i][j] = a;
            }
        }
    }
};