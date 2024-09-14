class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<bool> visit(intervals.size(),false);

        for(int i = 0;i<intervals.size();i++){
            for(int j = 0;j<intervals.size();j++){
                if(j == i){
                    continue;
                }
                if(!visit[j] && intervals[j][0] >= intervals[i][0] && intervals[j][1] <= intervals[i][1]){
                    visit[j] = true;
                } 
            }
        }
        int ans = 0;
        for(int i=0;i<visit.size();i++){
            if(visit[i] == false){
                ans++;
            }
        }
        return ans;
    }
};