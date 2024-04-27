class Solution {
public:
    int solve(vector<int> &cost,int n,vector<int> &track){
        if( n == 0 ){
            return cost[0];
        }
        if( n == 1 ){
            return cost[1];
        }
        if( track[n] != -1 ){
            return track[n];
        }
        track[n] = min(solve(cost,n-1,track),solve(cost,n-2,track))+cost[n];
        return track[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> track(n,-1);
        int ans = min(solve(cost,n-1,track),solve(cost,n-2,track));
        return ans;
    }
};