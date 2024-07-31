class Solution {
public:
// RECURSION
    // void solve(int i, vector<int>& coins, int amount, long long sum, int count,
    //            int& ans) {
    //     if (sum > amount) {
    //         return;
    //     }
    //     if (sum == amount) {
    //         ans = (ans == -1) ? count : min(ans, count);
    //         return;
    //     }
    //     for (int j = i; j < coins.size(); j++) {
    //         solve(j, coins, amount, sum + coins[j], count + 1, ans);
    //     }
    // }
// MEMOIZATION bottom to up
    int solve(vector<int> &coins,int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1;i<= amount;i++){
            for(auto coin : coins){
                if(i-coin >= 0 && dp[i-coin] != INT_MAX){
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // if (amount == 0) {
        //     return 0;
        // }
        // int ans = -1;
        // solve(0, coins, amount, 0, 0, ans);
        // return ans;
        return solve(coins,amount);
    }
};