class Solution {
public:
    void solve(vector<int> &cost,int n,vector<int> &track){
        track[0] = cost[0];
        track[1] = cost[1];

        for(int i = 2;i<n;i++){
            track[i] = min(track[i-1],track[i-2])+cost[i];
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> track(n,-1);
        solve(cost,n,track);
        int ans = min(track[n-2],track[n-1]);
        return ans;
    }
};