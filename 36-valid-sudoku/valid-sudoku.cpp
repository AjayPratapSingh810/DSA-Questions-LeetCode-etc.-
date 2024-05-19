class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows
        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> track(false);
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                if (val >= '1' && val <= '9' && track[val] == true) {
                    return false;
                }
                track[val] = true;
            }
        }
        // for cols
        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> track(false);
            for (int j = 0; j < 9; j++) {
                char val = board[j][i];
                if (val >= '1' && val <= '9' && track[val] == true) {
                    return false;
                }
                track[val] = true;
            }
        }
        int r = 0;
        int c = 0;
        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> track(false);
            for (int j = r; j < r + 3; j++) {
                for (int k = c; k < c + 3; k++) {
                    char val = board[j][k];
                    if (val >= '1' && val <= '9' && track[val] == true) {
                        return false;
                    }
                    track[val] = true;
                }
            }
            if(c != 6){
                c = c+3;
            }else{
                c = 0;
                r = r+3;
            }
        }
        return true;
    }
};