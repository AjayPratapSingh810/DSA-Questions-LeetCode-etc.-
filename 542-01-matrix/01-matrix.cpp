class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int> > > q;
        int size = mat.size();
        int size2 = mat[0].size();
        vector<vector<int> > ans(size,vector<int> (size2,0));
        vector<vector<bool> > visited(size,vector<bool> (size2,false));
        for(int i=0;i<mat.size();i++){
            for(int j= 0;j<mat[i].size();j++){
                if(mat[i][j] == 0){
                    q.push(make_pair(0,make_pair(i,j)));
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            pair<int,pair<int,int> > p = q.front();
            q.pop();
            int x = p.first;
            int i= p.second.first;
            int j= p.second.second;

            if(i>0 && !visited[i-1][j]){
                visited[i-1][j] = true;
                ans[i-1][j] = x+1;
                q.push(make_pair(x+1,make_pair(i-1,j)));
            }
            if(j<mat[i].size()-1 && !visited[i][j+1]){
                visited[i][j+1] = true;
                ans[i][j+1] = x+1;
                q.push(make_pair(x+1,make_pair(i,j+1)));
            } 
            if(i<mat.size()-1 && !visited[i+1][j]){
                visited[i+1][j] = true;
                ans[i+1][j] = x+1;
                q.push(make_pair(x+1,make_pair(i+1,j)));
            }
            if(j>0 && !visited[i][j-1]){
                visited[i][j-1] = true;
                ans[i][j-1] = x+1;
                q.push(make_pair(x+1,make_pair(i,j-1)));
            }
        }
        return ans;
    }
};