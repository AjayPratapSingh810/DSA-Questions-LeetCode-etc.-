class Solution {
public:
    int solve(int n,vector<int>& days, vector<int>& costs,int i,vector<int> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int option1 = costs[0] + solve(n,days,costs,i+1,dp);
        int j;
        // 7days pass;
        for(j = i;j<n && days[j] < days[i]+7;j++);
        int option2 = costs[1] + solve(n,days,costs,j,dp);

        for(j = i;j<n && days[j]<days[i]+30;j++);
        int option3 = costs[2] + solve(n,days,costs,j,dp);

        dp[i] =  min(option1,min(option2,option3));
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<int> dp(n,-1);
        return solve(n,days,costs,0,dp);
    }
};