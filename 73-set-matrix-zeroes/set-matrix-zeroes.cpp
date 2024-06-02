class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    arr.push_back(p);
                }
            }
        }
        for (int k = 0; k < arr.size(); k++) {
            pair<int, int> p = arr[k];
            int i = p.first;
            int j = p.second;

            // do row 0
            for (int k = 0; k < cols; k++) {
                matrix[i][k] = 0;
            }
            // do col 0
            for (int l = 0; l < rows; l++) {
                matrix[l][j] = 0;
            }
        }
    }
};