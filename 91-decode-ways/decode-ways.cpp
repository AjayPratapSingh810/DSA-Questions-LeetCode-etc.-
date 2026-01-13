class Solution {
public: 
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,0);
        return s.empty() ? 0 : solve(0,s,dp);
    }
    int solve(int i, string s, vector<int> &dp){
        int n = s.length();
        if(n == i){
            return 1;
        }
        if(s[i] == '0') return 0;
        if(dp[i] > 0){
            return dp[i];
        }
        int res = solve(i+1,s,dp);
        if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))){
            res += solve(i+2,s,dp);
        }
        dp[i] = res;
        return res;
    }
};