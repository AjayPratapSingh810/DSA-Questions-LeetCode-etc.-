class Solution {
public:
    int dp[200][200]{};
    int solve(int m,int n,vector<vector<int>>& grid){
        if(m == 0 && n == 0){
            return grid[0][0];
        }
        if(m < 0 || n < 0){
            return 0;
        }
        if(dp[m][n] !=0){
            return dp[m][n];
        }
        int one = INT_MAX;
        if(m-1 >= 0){
            one = solve(m-1,n,grid)+grid[m][n];
        }
        int two = INT_MAX;
        if(n-1 >= 0){
            two = solve(m,n-1,grid)+grid[m][n];
        }
        dp[m][n] = min(one,two);
        return min(one,two);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        return solve(m,n,grid);
    }
};