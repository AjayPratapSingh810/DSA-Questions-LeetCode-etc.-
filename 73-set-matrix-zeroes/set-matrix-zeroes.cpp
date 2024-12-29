class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int> > track;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    pair<int,int> p;
                    p.first = i;
                    p.second = j;
                    track.push_back(p);
                }
            }
        }

        for(int i = 0;i<track.size();i++){
            pair<int,int> p = track[i];
            int x = p.first;
            int y = p.second;

            for(int m = 0;m<matrix.size();m++){
                matrix[m][y] = 0;
            }
            for(int n = 0;n<matrix[0].size();n++){
                matrix[x][n] = 0;
            }
        }
    }
};