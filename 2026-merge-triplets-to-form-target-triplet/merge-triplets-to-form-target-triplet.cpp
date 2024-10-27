class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        queue<int> q;
        for(int i=0;i<triplets.size();i++){
            bool ok = true;
            for(int j=0;j<3;j++){
                if(triplets[i][j] > target[j]){
                    ok = false;
                }
            }
            if(ok){
                q.push(i);
            }
        }
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        while(!q.empty()){
                int i = q.front();
                q.pop();
                a = max(a,triplets[i][0]);
                b = max(b,triplets[i][1]);
                c = max(c,triplets[i][2]);
        }

        if(a != target[0] || b != target[1] || c != target[2]){
            return false;
        }
        return true;
    }
};