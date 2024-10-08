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
        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                if(j > 0){
                    pre[j][i] = pre[j][i]+pre[j-1][i];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum  = 0;
        sum = sum+pre[row2][col2];
        if(col1 > 0){
            sum = sum - pre[row2][col1-1];
        }
        if(row1 > 0){
            sum = sum - pre[row1-1][col2];
        }
        if(row1 > 0 && col1 > 0){
            sum = sum + pre[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */