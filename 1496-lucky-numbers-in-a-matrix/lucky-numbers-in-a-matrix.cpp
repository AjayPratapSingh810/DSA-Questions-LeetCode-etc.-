class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0;i<matrix.size();i++){
            int min = INT_MAX;
            int minIndex = -1;
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] < min){
                    min = matrix[i][j];
                    minIndex = j;
                }
            }
            int max = INT_MIN;
            int maxIndex = -1;
            for(int j = 0;j<matrix.size();j++){
                if(matrix[j][minIndex] > max){
                    max = matrix[j][minIndex];
                }
            }
            if(max == min){
                ans.push_back(max);
            }
            
        }
        return ans;
    }
};