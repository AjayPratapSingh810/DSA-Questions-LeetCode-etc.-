class NumMatrix {
public:
    vector<vector<int> > pre;
    NumMatrix(vector<vector<int>>& matrix) {
        pre = matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(j > 0){
                    pre[i][j] = pre[i][j]+pre[i][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x = row1;
        int y = col1;
        int sum  = 0;
        for(x;x<=row2;x++){
            if(col1 > 0){
                sum = sum + pre[x][col2]-pre[x][col1-1];
            }else{
                sum = sum + pre[x][col2];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */